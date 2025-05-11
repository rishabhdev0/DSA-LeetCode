class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(),s.end());
        int i = 0;// for looping 
        int left = 0;
        int right = 0; // for swapping 
        while(i<n){
            while(i<n && s[i] !=' '){
             s[right] = s[i];  // r ko i ki value assign kar do
             right++;
             i++;
            }
            if(left < right){
                reverse(s.begin()+ left , s.begin()+right);
                s[right++]=' ';  // har swap ke baad ek  extra space do
                left = right;  // left = right karo for new rverse
            }
            i++;
        }
     return s.substr(0, right-1);
    }
};