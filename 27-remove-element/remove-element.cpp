class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            if(nums[s]==val){
                nums[s]=nums[e];
                e--;
            }
            else{
                 s++;
            }
        }
        return s;
    }
};