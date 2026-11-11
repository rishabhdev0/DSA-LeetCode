class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int cost_both = cost1 + cost2;

        if (cost_both < costBoth) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        } 
        else {
            int mini = min(need1, need2);

            need1 -= mini;
            need2 -= mini;

            if (need1 > 0) {
                return 1LL * costBoth * mini + 
                       1LL * need1 * min(cost1, costBoth);
            } 
            else {
                return 1LL * costBoth * mini + 
                       1LL * need2 * min(cost2, costBoth);
            }
        }
    }
};
