class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        int fleetCount = 0;

        vector<pair<int , int>> p;

        for(int i = 0 ; i < n ; i++){
            p.push_back({position[i], speed[i]});
        }

        sort(p.begin(), p.end());  // sort by position

        double compare = 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            double reach_destination = (double)(target - p[i].first) / p[i].second;

            if(reach_destination > compare){
                fleetCount++;
                compare = reach_destination;
            }
        }

        return fleetCount;
    }
};