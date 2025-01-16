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

int ispossible(vector<int>&nums,int divsior,int threshold){ 
int n=nums.size();
int sum=0;
for(int i=0;i<n;i++){
    sum+=ceil(double(nums[i])/divsior);
}
return sum<=threshold;
}

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int result=-1;
        int s=1;
        int e=find_max(nums);
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(nums,mid,threshold)){
            result=mid;
            e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return result;
    }
};