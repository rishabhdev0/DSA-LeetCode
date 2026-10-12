class Solution {
public:
    #define ll long long
    ll mincount = LLONG_MAX;
    int n;

    void solve(vector<int>& jobs, int k , int idx , vector<ll>& workers){
        if(idx == n){
            ll maxi = *max_element(workers.begin() , workers.end());
            mincount = min(mincount , maxi);
            return;
        }

        for(int i = 0 ; i < k ; i++){
            workers[i] += jobs[idx];
            solve(jobs , k , idx + 1 , workers);
            workers[i] -= jobs[idx];
            if(workers[i] == 0) break;
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
         n = jobs.size();
        vector<ll>workers(k , 0);
        solve(jobs , k , 0 , workers);
        return (int)mincount;
    }
};