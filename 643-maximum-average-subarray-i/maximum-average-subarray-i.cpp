class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int n = nums.size();
       if(n==1){
        return nums[0];
       } 
       double window_sum = 0;
       int i = 0;
    //    calculating window sum
    while(i<k){
        window_sum+=nums[i];
        i++;
    }
    double max_avg = window_sum/k;
    while(i<n){
    window_sum+=nums[i]-nums[i-k];
    double curr_avg = window_sum/k;
    max_avg = max(max_avg, curr_avg);
    i++;
    }
    return max_avg;
    }
};