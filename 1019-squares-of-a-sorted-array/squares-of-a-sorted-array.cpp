class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sqrt(nums.size());
        int s = 0;  
        int e = nums.size() - 1; 
        int result = nums.size() - 1;  // Position to insert values into the sqrt array

        while (result>=0) {  
            int start = nums[s] * nums[s];
            int end = nums[e] * nums[e];

            if (start > end) {
                sqrt[result] = start;  
                s++; 
            } else {
                sqrt[result] = end; 
                e--;  
            }
            result--;  // Decrement result to move to the next position
        }
        return sqrt;
    }
};
