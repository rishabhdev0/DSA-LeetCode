class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n =  code.size();
        vector<int> result(n,0);
        if(k==0) return result;
         int i , j;
         if(k < 0){
             i = n - abs(k);
             j = n-1;
         }else{
             i = 1;
             j = k;
         }
         int first_k_sum=0;
         for(int idx = i ; idx<=j;idx++){
            first_k_sum+=code[idx];
         }

         for(int index = 0 ; index < n;index++){
            result[index] = first_k_sum;
            first_k_sum-= code[i%n];
            i++;
            first_k_sum +=code[(j+1)%n];
            j++;
         }
       return result;
    }
};