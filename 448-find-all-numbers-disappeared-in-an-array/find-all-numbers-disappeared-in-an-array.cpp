// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result;
//         sort(nums.begin(), nums.end());
        
//         int expected = 1;
//         int i = 0;
        
//         while(i < n && expected <= n) {
//             if(nums[i] == expected) {
//                 i++;
//                 expected++;
//             } else if(nums[i] < expected) {
//                 i++;
//             } else {
//                 result.push_back(expected);
//                 expected++;
//             }
//         }
        
//         // remianing value 
//         while(expected <= n) {
//             result.push_back(expected);
//             expected++;
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            if (count[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};
    