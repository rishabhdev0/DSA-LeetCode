// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();

//         vector<int> max_prefix(n);
//         vector<int> min_suffix(n);

//         // max_prefix
//         max_prefix[0] = arr[0];
//         for(int i = 1; i < n; i++){
//             max_prefix[i] = max(max_prefix[i-1], arr[i]);
//         }

//         // min_suffix
//         min_suffix[n-1] = arr[n-1];
//         for(int i = n-2; i >= 0; i--){
//             min_suffix[i] = min(min_suffix[i+1], arr[i]);
//         }

//         int chunks = 0;

//         for(int i = 0; i < n-1; i++){
//             if(max_prefix[i] <= min_suffix[i+1]){
//                 chunks++;
//             }
//         }

//         return chunks + 1; 
//     }
// };

// space optimization;

class Solution{
    public:
    int maxChunksToSorted(vector<int>nums){
       int n = nums.size();
       int max_so_far = 0;
       int chunks = 0;
       for(int i = 0 ; i < n ; i++){
        max_so_far = max(max_so_far , nums[i]);
        if(max_so_far == i){
            chunks++;
          }
       }
       return chunks;
    }
};