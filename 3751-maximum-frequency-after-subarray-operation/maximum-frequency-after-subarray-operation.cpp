class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int kCount = 0;
        for (int num : nums) if (num == k) kCount++;

        int best = 0;

        for (int v = 1; v <= 50; v++) {
            if (v == k) continue;
            int cur = 0;
            for (int num : nums) {
                if (num == v) cur++;
                else if (num == k) cur--;
                cur = max(cur, 0);
                best = max(best, cur);
            }
        }

        return kCount + best;
    }
};