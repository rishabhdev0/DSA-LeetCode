class Solution {
public:
    vector<vector<string>> result;
    vector<string> temp;

    bool isPalindrome(string &s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void backtracking(string &s, int idx) {
        if (idx >= s.length()) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                backtracking(s, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};