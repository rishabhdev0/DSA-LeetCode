class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
         int n = nums1.size();
         unordered_map<int , int>sum;
         for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sum[nums1[i] + nums2[j]]++;
            }
         }
         int count = 0;
         // now finding the sum on nums3 + nums4;
         for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int target = nums3[i] + nums4[j];
               if(sum.count(-target)){
                 count += sum[-target];
               }
            }
         }
         return count;
    }
};