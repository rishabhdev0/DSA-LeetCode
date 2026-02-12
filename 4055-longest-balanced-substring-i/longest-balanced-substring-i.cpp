class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;
        for(int i = 0 ; i < n ; i++){
            unordered_map<int , int>freq;
            for(int j = i ; j < n ; j++){
                freq[s[j]]++;
                int min_freq = INT_MAX;
                int max_freq = 0;
                for(auto it : freq){
                    min_freq = min(min_freq , it.second);
                    max_freq = max(max_freq , it.second);
                }
                if(min_freq == max_freq){
                    max_len = max(max_len , j - i + 1);
                }
            }
        }
        return max_len;
    }
};