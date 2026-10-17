class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        for(char ch = 'A' ; ch <= 'Z' ; ch++){
            int i = 0;
            int j =0;
            int replacement = k;
            while(j < n){
                if(s[j] != ch){
                    replacement--;
                }
                while(replacement < 0){
                    if(s[i] != ch){
                        replacement++;
                    }
                    i++;
                }
                maxLen = max(maxLen , j - i + 1);
                j++;
            }
        }
        return maxLen;
    }
};