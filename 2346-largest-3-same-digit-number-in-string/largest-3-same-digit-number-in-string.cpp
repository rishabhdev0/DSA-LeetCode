class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int i = 0, j = 0; // i = window start, j = window end
        string result = "";

        while (j < n) {
            // Window size exactly 3
             if (j - i + 1 == 3) {
                if (num[i] == num[i+1] && num[i] == num[i+2]) {
                    string temp = num.substr(i, 3);
                    if (temp > result) {
                        result = temp;
                    }
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
