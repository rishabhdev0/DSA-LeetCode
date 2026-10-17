class Solution {
public:
    int getDigit(int num){
        int sum = 0;
        while(num > 0){
            sum += num %  10;
            num /=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>freq;
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]] = i;
        }
        vector<int>afterSort(nums.begin() , nums.end());
        sort(afterSort.begin() , afterSort.end() , [&](int num1 , int num2){
           int d1 = getDigit(num1);
           int d2 = getDigit(num2);
           if(d1 == d2) return num1 < num2;
           return d1 < d2;
        });

        int swapCount = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == afterSort[i]) continue;
            swapCount++;
            int curr = afterSort[i];
            int idx = freq[curr];
            swap(nums[i] , nums[idx]);
            freq[nums[idx]] = idx;
            freq[nums[i]] = i;
        }
        return swapCount;
    }
};