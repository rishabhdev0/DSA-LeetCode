class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; 
        int n=nums.size();
        int k=2;
        int count=1;
        int s=1;
        for(int i=1;i<n;i++){
           if(nums[i]==nums[i-1]){
            count++;
            if(count <= k){
                nums[s]=nums[i];
                s++;
            }
           }
           else{
            count=1;
            nums[s]=nums[i];
            s++;
           }
        }
        return s;
    }
};