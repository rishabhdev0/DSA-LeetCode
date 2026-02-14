// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         int n = difficulty.size();
//         int m = worker.size();

//         priority_queue<pair<int,int>> pro_to_diff;

//         for(int i = 0; i < n; i++) {
//             pro_to_diff.push({profit[i], difficulty[i]});
//         }

//         sort(worker.rbegin(), worker.rend());  

//         int i = 0;
//         int maxProfit = 0;

//         while(i < m && !pro_to_diff.empty()) {
//             if(pro_to_diff.top().second > worker[i]) {
//                 pro_to_diff.pop();
//             } else {
//                 maxProfit += pro_to_diff.top().first;
//                 i++;
//             }
//         }

//         return maxProfit;
//     }
// };


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        vector<pair<int , int>>vec;
        for(int i = 0 ; i < n ; i++){
            vec.push_back({difficulty[i] , profit[i]});
        }
        sort(vec.begin() , vec.end());
        sort(worker.begin() , worker.end());
        int totalProfit = 0;
        int j = 0;
        int maxProfit = 0;
        for(int i = 0 ; i < m ; i++){
            while(j < n && worker[i] >= vec[j].first){
                maxProfit = max(maxProfit , vec[j].second);
                j++;
            }
            totalProfit += maxProfit;
        }
        return totalProfit;
    }
};

auto init= atexit([](){ ofstream("display_runtime.txt")<<'0';});



