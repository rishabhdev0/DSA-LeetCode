class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int result = 0;
        int n = s.length(); 

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                open++;
            } else if (ch == ')') {
                if (open > 0) {
                    open--;
                } else {
                    result++;
                }
            }
        }

        return result + open;
    }
};
