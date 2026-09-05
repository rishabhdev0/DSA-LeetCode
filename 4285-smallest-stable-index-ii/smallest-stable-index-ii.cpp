class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // smallest[i] = min(nums[i...n-1])
        vector<int> smallest(n);

        smallest[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            smallest[i] = min(nums[i], smallest[i + 1]);
        }

        int max_element = INT_MIN;

        for (int i = 0; i < n; i++) {
           
            max_element = max(max_element, nums[i]);

            
            int min_ele = smallest[i];

            int score = max_element - min_ele;

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};