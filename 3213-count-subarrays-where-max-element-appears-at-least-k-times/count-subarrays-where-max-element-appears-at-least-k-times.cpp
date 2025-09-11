class Solution {
private:
    int max_element(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
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
        int i = 0;
        int j = 0;
        
        while (j < n) {
            if (nums[j] == maxE) {
                count++;
            }
            
            while (count >= k) {
                result += n - j;
                if (nums[i] == maxE) {
                    count--;
                }
                i++;
            }
            j++; 
        }
        
        return result;
    }
};