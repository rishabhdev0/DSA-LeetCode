class Solution {
private:
    bool skip_left_right(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // we hqve to choose which one to remove left or right
                return skip_left_right(s, i + 1, j) || skip_left_right(s, i, j - 1);
            }
        }

        return true;
    }
};
