class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>best(n , INT_MAX);
        int i = 0;
        int j = 0;
        int sum = 0;
        int result = INT_MAX;
        int bestMinLen = INT_MAX;

        while(j < n){
            sum += arr[j];
            while(sum > target){
                sum -= arr[i];
                i++;
            }
            if(sum == target){
                int len = j - i + 1;
                // store the best subarray befoore i;
                if(i > 0 && best[i-1] != INT_MAX){
                    result = min(result , len + best[i-1]);
                }
                bestMinLen = min(bestMinLen , len);
            }
            best[j] = bestMinLen;
            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};