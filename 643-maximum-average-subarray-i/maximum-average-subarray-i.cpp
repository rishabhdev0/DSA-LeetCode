class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double answer = INT_MIN;
        long long sum = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            sum += nums[j];
            if(j - i + 1 > k){
                sum -= nums[i];
                i++;
            }
            if(j - i + 1 == k){
                double  avg = (double)sum / (j - i + 1);
                answer = max(answer , avg);
            }
            j++;
        }
        return answer;
    }
};