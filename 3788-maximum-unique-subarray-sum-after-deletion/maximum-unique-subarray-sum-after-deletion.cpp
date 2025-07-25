class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int sum = 0, maxEl = INT_MIN;

        for (int num : nums) {
            maxEl = max(maxEl, num); // for negative element
            if (num > 0 && seen.insert(num).second)
                sum += num;
        }

        return sum > 0 ? sum : maxEl;
    }
};
