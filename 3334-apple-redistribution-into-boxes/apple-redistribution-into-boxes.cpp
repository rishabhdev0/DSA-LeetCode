class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int total_sum = accumulate(apple.begin() , apple.end(), 0);
        int boxes = 0;
        int result = 0;
        sort(capacity.begin() , capacity.end());
        for(int i = m - 1 ; i >= 0 ; i--){
            boxes += capacity[i];
            result++;
            if(boxes >= total_sum){
                break;
            }
        }
       
        return result;
    }
};