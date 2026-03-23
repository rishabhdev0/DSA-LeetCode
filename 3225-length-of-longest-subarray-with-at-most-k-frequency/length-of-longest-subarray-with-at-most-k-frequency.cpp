class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int>freq;
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            freq[nums[j]]++;
            while(freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            j++;
            count = max(count , j - i);
        }
        return count;
    }
};