class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int next = -1;
            for (int j = 1; j < n; j++) {
                int idx = (i + j) % n;
                if (nums[idx] > nums[i]) {
                    next = nums[idx];
                    break; 
                }
            }
            result.push_back(next);
        }

        return result;
    }
};
