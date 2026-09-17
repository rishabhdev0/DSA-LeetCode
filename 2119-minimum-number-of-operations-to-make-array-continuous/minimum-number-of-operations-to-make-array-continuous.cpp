class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> seen(nums.begin(), nums.end());

        vector<int> temp(seen.begin(), seen.end());

        int result = n;

        for (int i = 0; i < temp.size(); i++) {
            int left = temp[i];
            int right = left + n - 1;

            int j = upper_bound(temp.begin(), temp.end(), right) - temp.begin();

            int withinRange = j - i;
            int outofRange = n - withinRange;

            result = min(result, outofRange);
        }

        return result;
    }
};