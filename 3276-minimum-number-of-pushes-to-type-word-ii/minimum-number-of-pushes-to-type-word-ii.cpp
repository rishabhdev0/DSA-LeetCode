class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char &ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int one_Cycle = 2;
        int count = 1;
        int result = 0;

        for (int i = 0; i < 26; i++) {
            if (one_Cycle > 9) {
                one_Cycle = 2;
                count++;
            }

            result += count * freq[i];
            one_Cycle++;
        }

        return result;
    }
};