class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // using line sweep algorithm
        int n = s.size();

        vector<int> nums(n + 1, 0);

        for(int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 1) {
                nums[start] += 1;
                nums[end + 1] -= 1;
            }
            else {
                nums[start] -= 1;
                nums[end + 1] += 1;
            }
        }

        // find cumulative sum
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        // finding the answer
        for(int i = 0; i < n; i++) {
            int shift = nums[i] % 26;

            if(shift < 0) {
                shift += 26;
            }

            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';
        }

        return s;
    }
};