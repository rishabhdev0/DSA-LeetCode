class Solution {
private:
    int operation(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b; 
        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result = operation(a, b, token);
                st.push(result);
             } else {
                st.push(stoi(token)); // only number
            }
        }
        return st.top();
    }
};