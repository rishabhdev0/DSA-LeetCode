class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();
        int j = n - 1;

       // sabse chota jth jaha j > j-1 na satisfy kare 
        while (j > 0 && nums[j] >= nums[j - 1]) {
            j--;
        }
        
        if (j == 0) return 0;

        int result = j; 
        int i = 0;

       
        while (i <= j && (i == 0 || nums[i] >= nums[i - 1])) {
           
            while (j < n && nums[i] > nums[j]) {
                j++;
            }
            result = min(result, j - i - 1);
            i++;
        }

        return result;
    }
};
