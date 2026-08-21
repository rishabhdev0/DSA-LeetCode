class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int evenCount = 1;
        int oddCount = 0;
        int count  = 0;
        int sum = 0;
        int mod = 1e9 + 7;
        for(int i = 0 ; i < n ; i++){
           sum += arr[i];
           if(sum % 2 == 0){
               count += oddCount;
               evenCount++;
           }else{
              count += evenCount;
              oddCount++;
           }
           count %= mod;
        }
        return count;
    }
};