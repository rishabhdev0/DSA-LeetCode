class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string vowels = "aeiou";
        int n = word.length();
        int max_len = 0;
        int i = 0;

        while (i < n) {
            // find until we get a 
            if (word[i] != 'a') {
                i++;
                continue;
            }

            int j = i; // starting of slifding window
            int vowel_index = 0; // keep track to vowel index for the correct order

            while (j < n && word[j] >= vowels[vowel_index]) {
                if (word[j] == vowels[vowel_index]) { // 
                //    continue;
                } else if (vowel_index < 4 && word[j] == vowels[vowel_index + 1]) {
                    vowel_index++; // move to next vowel
                } else {
                    break; // subsstring broken
                }
                j++;
            }

            // Check if all 5 vowels were found
            if (vowel_index == 4) {
                max_len = max(max_len, j - i);
            }

            // move to where the substring got broken
            i = j;
        }

        return max_len;
    }
};
