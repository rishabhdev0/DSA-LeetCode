class Solution {
private:
    void performoperation(stack<int>& st, const string& op) {
        if (op == "+") {
            int a = st.top();
             st.pop();
            int b = st.top();
            st.push(a);         
            st.push(a + b);
        } else if (op == "D") {
            st.push(st.top() * 2);
        } else if (op == "C") {
            st.pop();
        } else {
            st.push(stoi(op));
        }
    }

public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (const string& op : operations) {
            performoperation(st, op);
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};