class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        int i = 1;
        // increasing strictly
        if(nums[i] < nums[i-1]) return false;
        while(i < n && nums[i] > nums[i-1]){
            i++;
        }
        // strictly decreasing
        if(i == n || nums[i] > nums[i-1]) return false;
        while(i < n  && nums[i] < nums[i-1]){
            i++;
        }
        // again increasing
        if(i == n || nums[i] < nums[i-1]) return false;
        while(i < n && nums[i] > nums[i-1]){
            i++;
        }
        return i == n;
    }
};