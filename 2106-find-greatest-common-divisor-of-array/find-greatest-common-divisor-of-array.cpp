class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin() , nums.end());
        int biggest = *max_element(nums.begin() , nums.end());
        return __gcd(smallest , biggest);
    }
};