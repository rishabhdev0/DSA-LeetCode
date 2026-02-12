class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        
        int prev_group = 0;     
        int curr_group = 1;      
        int count_binary = 0;
        
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                curr_group++;
            } else {
                count_binary += min(prev_group, curr_group);
                prev_group = curr_group;
                curr_group = 1;
            }
        }
        
        // adding last pair
        count_binary += min(prev_group, curr_group);
        
        return count_binary;
    }
};
