class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int max_len = 0;

        for (int num : seen) {  // 🔥 iterate over set
            if (!seen.count(num - 1)) {
                int curr = num;
                int count = 1;

                while (seen.count(curr + 1)) {
                    curr++;
                    count++;
                }

                max_len = max(max_len, count);
            }
        }

        return max_len;
    }
};