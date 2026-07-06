class Solution {
public:
    int convert(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>freq;
        int maxSum = -1;

        for(int i = 0 ; i < n ; i++){
             int digitSum = convert(nums[i]);

             if(freq.count(digitSum)){
                maxSum = max(maxSum , nums[freq[digitSum]] + nums[i]);
                if(nums[i] > nums[freq[digitSum]]){
                    freq[digitSum] = i; // new i
                }
             }else{
                freq[digitSum] = i;
             }
        }
        return maxSum;
    }
};