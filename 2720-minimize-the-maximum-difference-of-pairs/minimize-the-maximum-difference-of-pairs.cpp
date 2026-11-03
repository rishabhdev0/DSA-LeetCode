
class Solution {
public:
    bool canpossible(vector<int>& nums, int target, int p) {
        int p_count = 0;

        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i] - nums[i - 1];

            if (val <= target) {
                p_count++;
                i++;
            }
        }

        return p_count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canpossible(nums, mid, p)) {
                high = mid;
            } 
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
