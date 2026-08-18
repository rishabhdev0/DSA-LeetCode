class Solution {
public:
    int maximumSwap(int num) {

        string s = to_string(num);
        int n = s.length();

        for (int i = 0; i < n; i++) {

            int max_val = -1;
            int max_idx = -1;

            for (int j = i + 1; j < n; j++) {

                if (s[i] < s[j]) {

                    if (max_val <= s[j] - '0') {
                        max_val = s[j] - '0';
                        max_idx = j;
                    }
                }
            }

            if (max_val != -1) {
                swap(s[i], s[max_idx]);
                return stoi(s);
            }
        }

        return num;
    }
};