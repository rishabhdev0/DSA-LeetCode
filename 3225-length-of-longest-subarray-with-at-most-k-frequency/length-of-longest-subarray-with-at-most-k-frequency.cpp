class Solution {
    // private:
    // bool good_subarray(unordered_map<int , int>& freq , int k ){
    //     for(auto& i : freq){
    //         if(i.second > k)return false;
    //     }
    //     return true;
    // }
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> freq;
        int max_subarray = 0;
        int i = 0;
        int j = 0;
        while(j<n){
           freq[nums[j]]++;
            while(freq[nums[j]] > k){
              freq[nums[i]]--;
              i++;
            }
            j++;
          max_subarray = max(max_subarray , j-i);
        }
    return max_subarray ;
    }
};