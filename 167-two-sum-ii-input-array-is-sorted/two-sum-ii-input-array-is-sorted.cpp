class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        int i = 0, j = n - 1;
        
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target) {
                result.push_back(i+1);
                result.push_back(j+1);
                return result; 
            } 
            else if(sum < target) {
                i++;
            } 
            else {
                j--;
            }
        }
        return result; 
    }
};
