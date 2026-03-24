class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin() , nums.end());
       int max_removal  = 0;
       int i = 0 ;
       int j  = 0;
       while(j < n){
          while((long long)nums[j] > (long long)k *  nums[i]){
            i++;
          }
          j++;
          max_removal = max(max_removal , j  - i +  1);
       }
       return n - max_removal + 1;
    }
};