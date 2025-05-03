class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0;
        int j = n-1;
        int k = n-1;
        while(k>=0){
           int s_square = nums[i]*nums[i];
           int e_square = nums[j]*nums[j];
           if(s_square < e_square){
          result[k]=e_square;
          j--;
           } else{
            result[k] = s_square;
            i++;
           }
           k--;
        }
        return result;
    }
};