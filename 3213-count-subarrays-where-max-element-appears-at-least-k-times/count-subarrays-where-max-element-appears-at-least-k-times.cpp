class Solution {
    private:
    int max_element(vector<int>&nums){
        int maxi = INT_MIN;
        for(int i = 0 ; i <nums.size();i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = max_element(nums);
        int n = nums.size();
        long long result = 0;
        int count = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxE) {
                count++;
            }

            while (count >= k) {
                result += n - right;
                if (nums[left] == maxE) {
                    count--;
                }
                left++;
            }
        }

        return result;
    }
};