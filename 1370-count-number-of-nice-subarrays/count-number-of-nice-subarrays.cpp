class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int odd_Count = 0;
        int result = 0;
        int i = 0;
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] % 2 != 0) {
                odd_Count++;
                count = 0; 
            }

            while (odd_Count == k) {
                count++;
                if (nums[i] % 2 != 0) {
                    odd_Count--;
                }
                i++;
            }

            result += count;
        }

        return result;
    }
};