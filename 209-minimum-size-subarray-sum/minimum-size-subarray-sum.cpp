class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int minL=INT_MAX;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            // doing smaall the window 
            while(sum>=target){
                minL=min(minL,j-i+1);
                sum-=nums[i]; // i ko minus karenge 
                i++;
            }
            j++;
        }
        return (minL == INT_MAX) ? 0 : minL; // agar minL int max se chota hai taab return karo min l aur size na achive ho paye to 0 return kar do 
    }
};