class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        int i = 0;
        int j = 0;
        int max_len = 0;
        
        while(j < n) {
            freq[s[j]]++;
            while(freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }
            
            max_len = max(max_len, j - i + 1);
            j++;
        }
        return max_len;
    }
};