class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // simple intution  -> left side me kitne even dekh rha hai prefix sum me;
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long even = 1;
        long long odd = 0;
        long long count = 0;
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                // odd + even =  odd;
                count += odd; // previsously last seen odd 
                even++;
            }else{
                count += even; // prevoisly even seen;
                odd++;
            }
            count %= MOD;
        }
        return count;
    }
};