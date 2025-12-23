// class Solution {
// public:
//     int sumOddLengthSubarrays(vector<int>& arr) {
//         int n = arr.size();
//         int oddSum = 0;

//         for (int i = 0; i < n; i++) {
//             int currSum = 0;
//             for (int j = i; j < n; j++) {
//                 currSum += arr[j]; 
//                 if ((j - i + 1) % 2 != 0) {
//                     oddSum += currSum;
//                 }
//             }
//         }
//         return oddSum;
//     }
// };

// using more optimal method

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd_count = 0;
        for(int i = 0 ; i < n ; i++){
            // find the total subarray that include the ith position
            int total = (i + 1) * (n - i);
            // find how many of them are odd
            int odd = (total + 1) /2;
            odd_count += odd * arr[i];
        }
        return odd_count;
    }
};    
