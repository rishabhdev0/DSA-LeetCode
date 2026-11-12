
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int insc_len = 1;
        int desc_len = 1;

        int ans = 1;

        for(int i = 1; i < n; i++) {

            if(nums[i] > nums[i-1]) {
                insc_len++;
            }
            else {
                insc_len = 1;
            }

            if(nums[i] < nums[i-1]) {
                desc_len++;
            }
            else {
                desc_len = 1;
            }

            ans = max(ans, max(insc_len, desc_len));
        }

        return ans;
    }
};
