class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;

        vector<pair<int,int>> p;
        for(auto it : freq){
            p.push_back({it.second, it.first});
        }

        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> result;
        for(auto &x : p){
            while(x.first--){
                result.push_back(x.second);
            }
        }
        return result;
    }
};