class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int>freq(26 , 0);
        int max_len = 0;
        int i = 0;
        int j = 0;
        int maxCount = 0;
        while(j < n){
            freq[s[j] - 'A']++;
            maxCount = max(maxCount , freq[s[j] - 'A']);
            if(j - i + 1 - maxCount > k){
                freq[s[i] - 'A']--;
                i++;
            }
            max_len = max(max_len , j - i + 1);
            j++;
        }
        return max_len;
    }
};