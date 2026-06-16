class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeroCount = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == 0){
                zeroCount++;
            }
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            if(i + zeroCount < n){
                arr[i + zeroCount] = arr[i];
            }
            if(arr[i] == 0){
                zeroCount--;
                if(i + zeroCount < n){
                    arr[i + zeroCount] = 0;
                }
            }
        }
    }
};