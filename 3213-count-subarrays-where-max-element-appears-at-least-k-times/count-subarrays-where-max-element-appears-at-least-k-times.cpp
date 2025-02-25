class Solution {
    private:
    int find_max(vector<int>nums){
        int maxi=INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE=find_max(nums);
        int n=nums.size();
        int i =0;
        int j=0;
        long long  result = 0;
        int max_count = 0;
        while(j<n){
         if(nums[j]==maxE){
            max_count++;
         }
            while(max_count >= k){
                result+=n-j;
               if(nums[i]==maxE){
                max_count--;
               }
               i++;
            }
            j++;
         }
     return result;
    }
};