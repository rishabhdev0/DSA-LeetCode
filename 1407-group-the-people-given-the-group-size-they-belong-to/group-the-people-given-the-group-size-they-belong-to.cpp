class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>result;
        unordered_map<int , vector<int>>freq;

        for(int i = 0 ;  i < n ; i++){
            int size = groupSizes[i];
            freq[size].push_back(i);
            if(freq[size].size() == size){
                result.push_back(freq[size]);
                freq[size].clear();
            }
        }
        return result;
    }
};