class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int max_dist = 0;
        int n = colors.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = n - 1 ; j >= i ; j--){
                if(colors[i] != colors[j]){
                    max_dist = max(max_dist , abs(i - j));
                }
            }
        }
        return max_dist;
    }
};