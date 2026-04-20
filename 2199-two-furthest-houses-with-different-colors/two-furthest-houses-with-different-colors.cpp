// class Solution {
// public:
//     int maxDistance(vector<int>& colors) {
//         int max_dist = 0;
//         int n = colors.size();
//         for(int i = 0 ; i < n ; i++){
//             for(int j = n - 1 ; j >= i ; j--){
//                 if(colors[i] != colors[j]){
//                     max_dist = max(max_dist , abs(i - j));
//                 }
//             }
//         }
//         return max_dist;
//     }
// };

// optimal 
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int max_dist = 0;
        int n = colors.size();

        
        int i = 0;
        while (colors[i] == colors[n-1]) i++;
        max_dist = max(max_dist, (n-1) - i);   

        
        int j = n - 1;
        while (colors[j] == colors[0]) j--;
        max_dist = max(max_dist, j);           

        return max_dist;
    }
};