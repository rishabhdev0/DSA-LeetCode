class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int n = nums.size();

        long long sum = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        int find = sum;

        while(seen.count(find)) {
            find++;
        }

        return find;
    }
};