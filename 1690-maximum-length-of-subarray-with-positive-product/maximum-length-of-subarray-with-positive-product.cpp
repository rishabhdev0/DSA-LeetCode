class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int s = i;
            int end = i;

            int count_neg = 0;
            int first_neg = -1;
            int last_neg = -1;

            // finding the end point until we get the zero 
            while (end < n && nums[end] != 0) {
                if (nums[end] < 0) {
                    count_neg++;
                    if (first_neg == -1)
                        first_neg = end;
                    last_neg = end;
                }
                end++;
            }

            // Case 1: Even negatives → full segment valid
            if (count_neg % 2 == 0) {
                max_len = max(max_len, end - s);
            } 
            else {
                // Case 2: Remove prefix till first negative
                if (first_neg != -1)
                    max_len = max(max_len, end - first_neg - 1);

                // Case 3: Remove suffix after last negative
                if (last_neg != -1)
                    max_len = max(max_len, last_neg - s);
            }

            i = end; 
        }

        return max_len;
    }
};