class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int start = i + 1;
            int end = n - 1;

            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];

                if (sum == 0) {
                    result.push_back({nums[i], nums[start], nums[end]});

                    // Skip duplicates for start and end
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;

                    start++;
                    end--;
                } 
                else if (sum < 0) {
                    start++;
                } 
                else {
                    end--;
                }
            }
        }
        return result;
    }
};
