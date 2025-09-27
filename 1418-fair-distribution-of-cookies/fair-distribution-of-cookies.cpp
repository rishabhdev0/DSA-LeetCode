class Solution {
public:
    int result = INT_MAX;
    int n;

    void backtrack(vector<int>& cookies, vector<int>& children, int k, int idx) {
        if (idx >= n) {
            int unfairness = *max_element(begin(children), end(children));
            result = min(result, unfairness);
            return;
        }

        int curr_cookies = cookies[idx];

        for (int i = 0; i < k; i++) {
            children[i] += curr_cookies;  // Give cookies[idx] to child i
            backtrack(cookies, children, k, idx + 1); //explore
            children[i] -= curr_cookies;  // Backtrack
            if(children[i] ==0) break;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k, 0);
        backtrack(cookies, children, k, 0);
        return result;
    }
};