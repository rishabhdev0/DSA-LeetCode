class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>vec(n * (n - 1) / 2);

        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int diff = abs(nums[i] - nums[j]);
                vec[idx] = diff;
                idx++;
            }
        }
        nth_element(vec.begin() , vec.begin() + k - 1 , vec.end());
        return vec[k-1];
    }
};