class Solution {
public:
    long long numberOfWays(string s) {
        long long totalZero = 0, totalOne = 0;
        for (char ch : s) {
            if (ch == '1') totalOne++;
            else totalZero++;
        }

        long long leftZero = 0, leftOne = 0, count = 0;

        for (char ch : s) {
            if (ch == '0') {
                // middle is '0' -> need 1 on left and 1 on right
                long long rightOne = totalOne - leftOne;
                count += leftOne * rightOne;
                leftZero++;
            } else {
                // middle is '1' -> need 0 on left and 0 on right
                long long rightZero = totalZero - leftZero;
                count += leftZero * rightZero;
                leftOne++;
            }
        }
        return count;
    }
};