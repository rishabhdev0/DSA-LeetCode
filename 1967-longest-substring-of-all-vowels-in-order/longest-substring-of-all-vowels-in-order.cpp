class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        int max_len = 0;
        int count = 1;  // number of vowels in order
        int len = 1;

        for (int i = 1; i < n; ++i) {
            if (word[i] >= word[i-1]) { // prev elem same or smaller
                len++;
                if (word[i] != word[i-1]) { // uniqu vovwel count 
                    count++;
                }
                if (count == 5) { // all 5 vowel find
                    max_len = max(max_len, len);
                }
            } else {
               // of order break then we start over
                if (word[i] == 'a') {
                    len = 1;
                    count = 1;
                } else {
                    len = 0;
                    count = 0;
                }
            }
        }

        return max_len;
    }
};
