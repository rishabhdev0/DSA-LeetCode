// class Solution {
// public:
//     int findFinalValue(vector<int>& nums, int original) {
//         int n = nums.size();
//         sort(nums.begin() , nums.end());
//         for(int num : nums){
//             if(num == original){
//                 original *=2;
//             }
//         }
//         return original;
//     }
// };

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> seen(nums.begin(), nums.end());
        
        while (seen.count(original)) {
            original *= 2;
        }
        
        return original;
    }
};