class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        unordered_set<int>seen;
        int max_Len = 0;
        while(j < n){
            while(seen.count(s[j])){
                seen.erase(s[i]);
                i++;
            }
            seen.insert(s[j]);
            max_Len = max(max_Len , j - i + 1);
            j++;
        }
        return max_Len;
    }
};