class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        int mod = 1e9 + 7;
        long long result = 0;
        long long count = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                count++;
                result = (result + count) % mod;
            } else {
                count = 0;
            }
        }
        
        return result;
    }
};