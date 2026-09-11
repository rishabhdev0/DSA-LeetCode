class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        unordered_map<int , int>freq;
        for(int j = 0 ; j < n ; j++){
            int val = nums[j] - j;
            int how_many = freq[val];
            count += how_many;
            freq[val]++;
        }
        long long total_pairs = 1LL * n * (n - 1)  / 2;
        return total_pairs - count;
    }
};