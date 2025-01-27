class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(n < 2) return n;  
        
        int st = 0;
        int e = n-1;
        
        while(st < e && s[st] == s[e]) {
            char ch = s[st];
            while(st < e && s[st] == ch) st++;
            while(st <= e && s[e] == ch) e--;
        }
        return e - st + 1;
    }
};