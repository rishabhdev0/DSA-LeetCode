class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch : s) {
            
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            
           
            if(st.empty()) return false; 
            
            if(ch == ')') {
                if(st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }
            else if(ch == '}') {
                if(st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
            else if(ch == ']') {
                if(st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};