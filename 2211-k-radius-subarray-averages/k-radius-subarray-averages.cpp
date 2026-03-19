class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result(n , -1);
        long long  sum = 0;
        int i = 0;
        int j = 0;

        while(j < n){
            sum += nums[j];
            if(j - i + 1 == 2 * k + 1){
                int average = sum / (2 * k + 1);
                result[i+k] = average;
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return result;
    }
};