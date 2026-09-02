class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();
        int max_Len = 0;

        
        for (char ch = 'A'; ch <= 'Z'; ch++) {

            int i = 0;
            int j = 0;

            
            int replacements = k;

            while (j < n) {

                
                if (s[j] != ch) {
                    replacements--;
                }

               
                while (replacements < 0) {

                    
                    if (s[i] != ch) {
                        replacements++;
                    }

                    i++;
                }

               
                max_Len = max(max_Len, j - i + 1);

                j++;
            }
        }

        return max_Len;
    }
};