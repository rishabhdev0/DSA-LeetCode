class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        int i = 0 ;
        int l = 0 , r = 0;
        while(i<n){
            while(i < n && s[i] !=' '){ // agar space nhi mila to 
             s[r++] = s[i++]; // r ko i ki value assign kar do aur aage badho
            } 
            if(l<r){
              reverse(s.begin()+l , s.begin()+r);
           s[r]= ' '; // ek space asign kar do 
           r++;
           l=r;  // reverse kar do l , r tak
            }
           i++;
        }
        return s.substr(0 , r-1);
    }
};