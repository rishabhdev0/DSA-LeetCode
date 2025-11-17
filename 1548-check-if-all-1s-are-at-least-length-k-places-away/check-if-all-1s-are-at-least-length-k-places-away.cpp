class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = k; // first '1' is allowed
        
        for(int num : nums) {
            if(num == 1) {
                if(count < k) return false;
                count = 0;
            } else {
                count++;
            }
        }
        return true;
    }
};