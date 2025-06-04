class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int count = 0; // index for nums
        for(int i = 1; ; i++) {
            if(count < nums.size() && nums[count] == i) {
                count++; 
            } else {
                k--;
                if(k == 0) return i; 
            }
        }
        return -1; 
    }
};
