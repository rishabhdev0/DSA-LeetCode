// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> freq(n + 1, 0);
//         vector<int> result(2);

//         for(int num : nums) {
//             freq[num]++;
//         }
        
//         for(int i = 1; i <= n; i++) {
//             if(freq[i] == 2) {
//                 result[0] = i; // duplicate
//             }
//             if(freq[i] == 0) {
//                 result[1] = i; // missing
//             }
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums){
        int n = nums.size();
        vector<int> result(2);
        
        sort(nums.begin(), nums.end());
        
        // Find duplicate
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                result[0] = nums[i];
                break;
            }
        }
        
        // Find missing number
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for(int num : nums) {
            actualSum += num;
        }
        
        // missing = expectedSum - (actualSum - duplicate)
        result[1] = expectedSum - (actualSum - result[0]);
        
        return result;
    }
};