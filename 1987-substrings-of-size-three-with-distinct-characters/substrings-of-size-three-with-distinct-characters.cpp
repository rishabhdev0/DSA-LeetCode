class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int k = 3;
        unordered_map<char,int> freq;
        int i = 0, j = 0, count = 0;

        while (j < n) {
            freq[s[j]]++;
            if (j - i + 1 == k) {
                if (freq.size() == k) {
                    count++;
                }
                freq[s[i]]--;
                if (freq[s[i]] == 0) freq.erase(s[i]); // remove right element compleltely
                i++;
            }
            j++;
        }
        return count;
    }
};