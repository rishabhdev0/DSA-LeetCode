class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxLen  = 0;
        unordered_map<int , int>freq;
        while(j < n){
            freq[s[j]]++;
            while(freq[s[j]] > 2){
                freq[s[i]]--;
                i++;
            }
            maxLen = max(maxLen , j - i + 1);
            j++;
        }
        return maxLen;
    }
};