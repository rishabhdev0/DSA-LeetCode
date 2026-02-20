class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        long long sum = 0;
        for(int i = 0 ; i < n ;  i++){
            sum+=nums[i];
            result[i] = sum;
        }
        return result;
    }
};