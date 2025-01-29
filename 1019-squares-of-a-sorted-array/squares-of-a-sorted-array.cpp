class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sqrt(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sqrt[i] = nums[i] * nums[i];  
        }
        sort(sqrt.begin(), sqrt.end());  
        return sqrt;  
    }
};
