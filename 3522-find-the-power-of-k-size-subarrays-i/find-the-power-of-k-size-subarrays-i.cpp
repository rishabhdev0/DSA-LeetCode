class Solution {
public:
  bool isSorted(vector<int>& nums , int left , int right){
    for(int i = left + 1 ; i <= right ; i++){
        if(nums[i] != nums[i-1] + 1){
            return false;
        }
    }
    return true;
  }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result(n - k + 1 , -1);
        int i = 0;
        int j = 0;
        while(j < n){
            if(j - i + 1 > k)i++;
            if(j - i + 1 == k){
                if(isSorted(nums , i , j)){
                    result[i] = nums[j];
                }
                i++;
            }
            j++;
        }
        return result;
    }
};