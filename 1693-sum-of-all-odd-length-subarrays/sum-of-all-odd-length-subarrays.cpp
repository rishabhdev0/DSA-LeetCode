class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int oddSum = 0;

        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += arr[j]; 
                if ((j - i + 1) % 2 != 0) {
                    oddSum += currSum;
                }
            }
        }
        return oddSum;
    }
};
