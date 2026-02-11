class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Build unique array correctly
        vector<int> unique;
        unique.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                unique.push_back(nums[i]);
            }
        }

        int i = 0;
        int j = 0;
        int m = unique.size();
        int max_len = 0;

        while(j < m) {

            while(unique[j] - unique[i] >= n) {
                i++;
            }

            max_len = max(max_len, j - i + 1);
            j++;
        }

        return n - max_len;
    }
};
