class Solution {
    private:
    int find_max(vector<int>&nums){
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        return maxi;
    }

    int ispossible(vector<int>&nums,int value,int maxOperations){
        int count = 0;
       for (int num : nums) {
            count += (num - 1) / value;  
            if (count > maxOperations) return false;  
        }
        return count <= maxOperations;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int s=1;
        int e=find_max(nums);
        int result=s;
        while(s<=e){
            int mid=s+(e-s)/2;
             if(ispossible(nums,mid,maxOperations)){
            result=mid;
             e=mid-1;
        }
        else {
            s=mid+1;
        }
             }
          
        return result;

    }
};