class Solution {
private:
    long long findCost(vector<int>& nums, vector<int>& cost, int target) {
        long long totalCost = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalCost += (long long)abs(nums[i] - target) * cost[i];
        }
        return totalCost;
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        long long result = LLONG_MAX;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long currentCost = findCost(nums, cost, mid);
            long long nextCost = findCost(nums, cost, mid + 1);
            
            result = min(result, currentCost);
            
            if(nextCost > currentCost) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result == LLONG_MAX ? 0 : result;
    }
};