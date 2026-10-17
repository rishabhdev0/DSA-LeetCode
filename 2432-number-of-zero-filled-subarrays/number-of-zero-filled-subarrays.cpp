class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        long  long count = 0;
        int i = 0;
        while(i < n){
            if(nums[i] == 0){
            while(i < n && nums[i] == 0){
                count++;
                i++;
                }
                answer += count * (count + 1) / 2;
                count = 0;
            }else{
                i++;
            }
        }
        return answer;
    }
};