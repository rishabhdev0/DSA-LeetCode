class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char &ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            
            // If it's a closing bracket and stack is empty
            if (st.empty()) {
                return false;
            }
            if ((ch == ')' && st.top() == '(') ||
                (ch == ']' && st.top() == '[') ||
                (ch == '}' && st.top() == '{')) {
                st.pop();
            } else {
                // Mismatched brackets
                return false;
            }
        }
        return st.empty();
    }
};