class Solution {
public:
    int atmost(vector<int>& nums , int k){
        unordered_map<int , int>freq;
        int n = nums.size();
        int i =0;
        int j = 0;
        int count = 0;
        while(j < n){
            freq[nums[j]]++;
            while(freq.size() > k){
               freq[nums[i]]--;
               if(freq[nums[i]] == 0){
                 freq.erase(nums[i]);
               }
               i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums , k) - atmost(nums , k - 1);
    }
};