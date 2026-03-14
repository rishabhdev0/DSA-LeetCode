class Solution {
public:

    vector<int> dp;

    int getNextIndex(vector<vector<int>>& arr, int l, int target){
        int r = arr.size() - 1;
        int result = arr.size();

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(arr[mid][0] >= target){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>& arr, int idx){

        if(idx >= arr.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int next = getNextIndex(arr, idx + 1, arr[idx][1]);

        int take = arr[idx][2] + solve(arr, next);

        int not_take = solve(arr, idx + 1);

        return dp[idx] = max(take, not_take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> arr(n, vector<int>(3));

        for(int i = 0; i < n; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());

        dp.resize(n, -1);

        return solve(arr, 0);
    }
};