class Solution {
private:
    // Sliding window function to count pairs with distance <= Dist
    int slidingWindow(vector<int> &nums, int Dist, int n) {
        int i = 0;
        int Pair_Count = 0;
        
        for (int j = 0; j < n; j++) {
            while (nums[j] - nums[i] > Dist) {
                i++;
            }
            Pair_Count += (j - i);
        }
        return Pair_Count;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0;
        int e = nums[n - 1] - nums[0];
        int result = 0;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (slidingWindow(nums, mid, n) < k) {
                s = mid + 1;
            } else {
                result = mid;
                e = mid - 1;
            }
        }
        return result;
    }
};
