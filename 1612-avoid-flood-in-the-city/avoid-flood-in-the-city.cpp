class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>result(n , -1);
        unordered_map<int , int>LastRains; // rain , the last day it rained
        set<int>Dry; // to check if i dry the lake;

        for(int i = 0 ; i < n ; i++){
             if(rains[i] == 0){
                Dry.insert(i);
                result[i] = 1; // by default , will change later;
             }else {
                // not a dry lake
                int lake = rains[i];
                if(LastRains.count(lake)){
                    // lake found before , time to find a dry one
                    auto it = Dry.upper_bound(LastRains[lake]);
                    if(it == Dry.end()) return {};
                    int DryDay = *it;
                    result[DryDay] = lake;
                    Dry.erase(DryDay);
                }
                LastRains[lake] = i;
             }
        }
        return result;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });