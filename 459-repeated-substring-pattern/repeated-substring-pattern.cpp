class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int len = n / 2 ;  len >= 1 ; len--){
            if(n % len == 0){
                int times = n / len;
                string pattern = s.substr(0 , len);
                string result = "";
                while(times--){
                    result += pattern;
                }
                if(result == s) return true;
            }
        }
        return false;
    }
};