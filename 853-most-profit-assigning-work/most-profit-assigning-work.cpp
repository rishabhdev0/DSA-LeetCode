class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int , int>>diff_pro(profit.size());
        for(int i = 0 ; i < profit.size() ; i++){
            diff_pro[i] = {difficulty[i] , profit[i]};
        }
        sort(diff_pro.begin() , diff_pro.end());

        for(int i = 1 ; i < profit.size() ; i++){
            diff_pro[i].second = max(diff_pro[i].second , diff_pro[i-1].second);
        }
        long long most_profit = 0;

        for(int i = 0 ; i < worker.size() ; i++){
            int idx = upper_bound(diff_pro.begin() , diff_pro.end() , make_pair(worker[i], INT_MAX)) - diff_pro.begin();
            if(idx > 0){
                most_profit += diff_pro[idx-1].second;
            }
        }
        return most_profit;
    }
};