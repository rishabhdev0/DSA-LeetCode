class Solution {
public:
    vector<string> result;

    bool is_balanced(string& curr) {
        int open_count = 0;
        for (char c : curr) {
            if (c == '(') {
                open_count++;
            } else {
                open_count--;
            }
            if (open_count < 0) return false; 
        }
        return open_count == 0;
    }

    void generate(string& curr, int n) {
        if (curr.length() == 2 * n) {
            if (is_balanced(curr)) {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        generate(curr, n);
        curr.pop_back();

        curr.push_back(')');
        generate(curr, n);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        generate(curr, n);
        return result;
    }
};
