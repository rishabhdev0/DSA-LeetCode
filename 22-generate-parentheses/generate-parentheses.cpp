class Solution {
public:
    vector<string> result;

    void generate(string& curr, int n, int open, int closed) {
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            generate(curr, n, open + 1, closed);
            curr.pop_back();
        }

        if (closed < open) {
            curr.push_back(')');
            generate(curr, n, open, closed + 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        generate(curr, n, 0, 0);
        return result;
    }
};