class Solution {
    private:
    int max_element(vector<int>& nums){
        int maxi= INT_MIN;
        for(int i = 0 ; i < nums.size();i++){
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0 ;
        long long result = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxE= max_element(nums);
        while(j<n){
            if(nums[j]==maxE){
                count++;
            }
            while(count >=k){
                result+=n-j;
                if(nums[i]==maxE){
                    count--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};