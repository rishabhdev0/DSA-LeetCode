class Solution {
public:
    vector<vector<string>> result;
    vector<string> temp;

    bool palindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }

        return true;
    }

    void backtracking(int idx, string &s) {

        if (idx == s.length()) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < s.length(); i++) {

            string curr = s.substr(idx, i - idx + 1);

            if (palindrome(curr)) {

                temp.push_back(curr);

                backtracking(i + 1, s);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        backtracking(0, s);

        return result;
    }
};