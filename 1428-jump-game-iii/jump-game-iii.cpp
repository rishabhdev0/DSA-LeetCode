class Solution {
public:
    bool solve(vector<int>& arr, int idx) {

        // out of bounds OR already visited
        if(idx < 0 || idx >= arr.size() || arr[idx] < 0) {
            return false;
        }

        if(arr[idx] == 0) {
            return true;
        }

        int jump = arr[idx];

        // mark visited so no cycle is detetcetd
        arr[idx] *= -1;

        bool a = solve(arr, idx + jump);
        bool b = solve(arr, idx - jump);

        return a || b;
    }

    bool canReach(vector<int>& arr, int start) {
        return solve(arr, start);
    }
};