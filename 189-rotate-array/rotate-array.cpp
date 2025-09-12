class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k  = k % n;
        // reverse whole array;
        reverse(nums.begin() , nums.end());
        // now reverse k array 
        reverse(nums.begin() , nums.begin() + k);
        // now rest
        reverse(nums.begin() +  k , nums.end());
    }
};