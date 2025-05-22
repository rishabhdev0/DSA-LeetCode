class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left_sum = 0;
        int right_sum =  0;
        for(int i =n-k;i<n;i++){
            right_sum +=nums[i];
        }
        int max_sum = right_sum;

        int j = 0;
        while(j<k){
            right_sum -=nums[n-k+j];
            left_sum +=nums[j];
             max_sum = max(max_sum , left_sum + right_sum);
             j++;
        }
        return max_sum;
    }
};