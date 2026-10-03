class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int longestValid = 0;
        int open = 0;
        int closed = 0;

        // Left to right
        for(char &ch : s) {

            if(ch == '(') {
                open++;
            }
            else {
                closed++;
            }

            if(closed > open) {
                open = 0;
                closed = 0;
            }

            if(open == closed) {
                longestValid = max(longestValid, open + closed);
            }
        }

        open = 0;
        closed = 0;

        // Right to left
        for(int i = n - 1; i >= 0; i--) {

            if(s[i] == '(') {
                open++;
            }
            else {
                closed++;
            }

            if(open > closed) {
                open = 0;
                closed = 0;
            }

            if(open == closed) {
                longestValid = max(longestValid, open + closed);
            }
        }

        return longestValid;
    }
};