class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int n = nums.size();
       int max_score = 0;
       unordered_set<int>seen;
       int i = 0;
       int j = 0;
       int curr_sum = 0;
       while(j < n){
        while(seen.count(nums[j])){
            seen.erase(nums[i]);
            curr_sum -= nums[i];
            i++;
        }
        seen.insert(nums[j]);
        curr_sum += nums[j];
        max_score = max(max_score , curr_sum);
        j++;
       } 
       return max_score;
    }
};