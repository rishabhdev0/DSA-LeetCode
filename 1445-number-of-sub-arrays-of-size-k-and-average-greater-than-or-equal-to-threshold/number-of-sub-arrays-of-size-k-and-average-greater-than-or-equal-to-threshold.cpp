class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0;
        int i = 0;
        int j = 0;
        long long sum = 0;
        while(j < n){
            sum += arr[j];
            if(j - i + 1 == k){
                int average = sum / k;
                if(average >= threshold){
                    count++;
                }
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return count;
    }
};