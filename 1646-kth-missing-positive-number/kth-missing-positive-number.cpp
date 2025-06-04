class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int current = 1;
        int i = 0;
        while (k > 0) {
            if (i < nums.size() && nums[i] == current) {
                i++; //number is there , we move
            } else {
                k--; 
                if (k == 0) return current;
            }
            current++;
        }
        return -1; // should never be hit
    }
};
