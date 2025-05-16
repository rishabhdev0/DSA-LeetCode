class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int zero_count = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                zero_count++;
            }
        }

        long long swap_count = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != '0') {
                swap_count += zero_count;
            } else {
                zero_count--;
            }
        } 

        return swap_count;
    }
};
