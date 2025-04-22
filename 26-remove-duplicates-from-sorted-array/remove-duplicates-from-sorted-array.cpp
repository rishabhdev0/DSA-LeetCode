class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int unique_index = 0;
        int i = 1;
        int n = nums.size();
        
        while (i < n) {
            if (nums[i] != nums[unique_index]) {
                unique_index++;
                nums[unique_index] = nums[i];
                // unique_index++;
            }
            i++;
        }
        
        return unique_index + 1;
    }
};