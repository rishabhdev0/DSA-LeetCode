class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        for(int i = 0 ; i < n ; i++){
            unordered_set<int>oddCount;
            unordered_set<int>evenCount;
            for(int j = i ; j < n ; j++){
                if(nums[j] % 2 == 0){
                    evenCount.insert(nums[j]);
                }else {
                    oddCount.insert(nums[j]);
                }
                if(oddCount.size() == evenCount.size()){
                    max_len = max(max_len , j - i + 1);
                }
            }
        }
        return max_len;
    }
};