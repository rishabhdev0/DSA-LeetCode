class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // matched[i] = maximum number of characters of word2
        // that can be matched using word1[i...n-1]
        vector<int> matched(n + 1, 0);

        int match = 0;
        int i = n - 1;
        int j = m - 1;

        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                match++;
                j--;
            }

            matched[i] = match;
            i--;
        }

        bool canChange = true;
        vector<int> result;

        i = 0;
        j = 0;

        while (i < n && j < m) {

            // Normal matching
            if (word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            }

            // Use our one allowed change
            else if (canChange && matched[i + 1] >= m - j - 1) {
                result.push_back(i);
                j++;
                canChange = false;
            }

            i++;
        }

        return j == m ? result : vector<int>();
    }
};