class Solution {
public:
    int getDigit(int num){
        int new_num = 0;
        while(num > 0){
            new_num += num % 10;
            num /= 10;
        }
        return new_num;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int digit = getDigit(nums[i]);
            if(digit == i) return i;
        }
        return -1;
    }
};