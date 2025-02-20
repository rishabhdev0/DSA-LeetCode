class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int count_zeros=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                count_zeros++;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(i+count_zeros<n){
                arr[i+count_zeros]=arr[i];
            }
            if(arr[i]==0){
                count_zeros--;
                if(i+count_zeros<n){
                    arr[i+count_zeros]=0;
                }
            }
        }    
    }
};