class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int minElement = INT_MAX;

        for(int num : nums){
            sum += num;
            minElement = min(minElement , num);
        }
        return sum - n * minElement;
    }
};