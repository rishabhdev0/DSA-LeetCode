#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
private:
    int operation(int a, int b, string token) {
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") return a / b;
        return -1;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                int result = operation(a, b, token);  
                st.push(result);
            } else {
                st.push(stoi(token)); 
            }
        }
        return st.top();
    }
};