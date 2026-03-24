class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1, -1);
        
        int i = 0, j = 0;
        int count = 1;
        
        while (j < n) {
            if (j > 0 && nums[j] == nums[j - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
            
            if (j - i + 1 == k) {
                if (count >= k) {
                    result[i] = nums[j];
                }
                i++; 
            }
            
            j++;
        }
        
        return result;
    }
};