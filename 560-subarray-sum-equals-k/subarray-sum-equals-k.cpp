class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>freq;
        freq[0] = 1;
        int result = 0;
        int currSum = 0;
        for(int num : nums){
            currSum += num;
            if(freq.count(currSum - k)){
                result += freq[currSum - k];
            }
            freq[currSum]++;
        }
        return result;
    }
};