class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int>result(n);
        sort(potions.begin() , potions.end());

        for(int i = 0 ; i < n ; i++){
            int left = 0;
            int end = m - 1;
            while(left <= end){
                int mid = left + (end - left) / 2;
                if(1LL * spells[i] * potions[mid] >= success){
                    end = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            result[i] = m - left;
        }
        return result;
    }
};