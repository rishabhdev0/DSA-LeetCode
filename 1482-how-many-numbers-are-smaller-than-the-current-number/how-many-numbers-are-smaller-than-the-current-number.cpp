// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result(n);
//         for(int i = 0; i < n; i++) {
//             int count = 0;
//             for(int j = 0; j < n; j++) {
//                 if(nums[j] < nums[i]) {
//                     count++;
//                 }
//             }
//             result[i] = count;
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            // Find the first occurrence of nums[i] in sorted array
            auto it = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]);
            result[i] = distance(sortedNums.begin(), it);
        }
        return result;
    }
};  