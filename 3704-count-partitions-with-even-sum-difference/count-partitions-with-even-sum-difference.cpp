class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for(int num : nums) {
            total += num;
        }
        
        int leftsum = 0;
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            leftsum += nums[i];  
            int rightsum = total - leftsum;
            
            if((leftsum - rightsum) % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }
};