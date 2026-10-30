class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int min_Len = INT_MAX;
        unordered_map<int , int>freq;
        int i = 0;
        int j = 0;
        while(j < n){
           if(freq[cards[j]] > 0){
              min_Len = min(min_Len , j - i + 1);
              freq[cards[i]]--;
              i++;
           }else{
            freq[cards[j]]++;
            j++;
           }
        }
         return min_Len == INT_MAX ? -1  : min_Len;
    }
};