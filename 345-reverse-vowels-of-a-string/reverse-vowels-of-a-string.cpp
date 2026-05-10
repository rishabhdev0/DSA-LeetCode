class Solution {
public:
    
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
   
    string reverseVowels(string s) {
        int n = s.length();

        int i = 0;
        int j = n - 1;

        while(i <= j){

            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!isVowel(s[i])){
                i++;
            }
            else{
                j--;
            }
        }

        return s;
    }
};