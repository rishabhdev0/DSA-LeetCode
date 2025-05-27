class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> freq;
        for(int num:nums){
            freq[num]++;
        }
       int total_unique_count = freq.size();
       int count_result = 0;
       unordered_map<int , int> window_freq;
       int i  = 0;
       int j = 0;

       while(j<n){
        int curr = nums[j];
        window_freq[curr]++;
        while(window_freq.size() ==total_unique_count){
           count_result+=n-j;
           window_freq[nums[i]]--;
           if(window_freq[nums[i]]==0){
            window_freq.erase(nums[i]);
           }
           i++;
            }
            j++;
       }
       return count_result;
    }
};