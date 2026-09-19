class Solution {
public:

    int getDigit(int num){
        int sum = 0;

        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {

        unordered_map<int,int> freq;

        int max_sum = -1;

        for(int i = 0; i < nums.size(); i++){

            int digit = getDigit(nums[i]);

            if(freq.count(digit)){

                max_sum = max(max_sum, freq[digit] + nums[i]);

                freq[digit] =
                    max(freq[digit], nums[i]);
            }
            else{
                freq[digit] = nums[i];
            }
        }

        return max_sum;
    }
};