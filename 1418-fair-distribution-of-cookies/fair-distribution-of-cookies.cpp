class Solution {
public:
    int result = INT_MAX;

    void backtracking(vector<int>& cookies, vector<int>& children, int k, int idx) {
        if(idx >= cookies.size()) {
            int unfairness = *max_element(begin(children), end(children));
            result = min(result, unfairness);
            return;
        }

        int curr_Cookies = cookies[idx];

        for(int i = 0; i < k; i++) {
            children[i] += curr_Cookies;

            backtracking(cookies, children, k, idx + 1);

            children[i] -= curr_Cookies;

            if(children[i] == 0) break;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);

        backtracking(cookies, children, k, 0);

        return result;
    }
};