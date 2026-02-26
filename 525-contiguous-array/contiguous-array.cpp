class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>freq;
        freq[0] = -1;
        int maxLen = 0;
        int currSum = 0;
        for(int i = 0 ; i < n ; i++){
            currSum += (nums[i] == 0 ? -1 : 1);
            if(freq.find(currSum) != freq.end()){
                maxLen = max(maxLen , i - freq[currSum]);
            }else{
                freq[currSum] = i;
            }
        }
        return maxLen;
    }
};