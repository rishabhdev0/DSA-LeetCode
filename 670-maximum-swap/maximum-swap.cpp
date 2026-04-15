class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        
        vector<int> last(10, -1);
        
        // Store last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        // Traverse digits
        for (int i = 0; i < n; i++) {
            // find the bigger number
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        
        return num;
    }
};