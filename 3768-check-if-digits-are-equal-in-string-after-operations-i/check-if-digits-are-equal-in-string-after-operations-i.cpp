class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string result = "";
            for (int i = 0; i < s.length() - 1; i++) {
                int first = s[i] - '0';
                int second = s[i + 1] - '0';
                int sum = (first + second) % 10;
                result += to_string(sum);
            }
            s = result; 
        }
        return s[0] == s[1];
    }
};
