class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool>seen(n , false);
        vector<int>result;
        for(int i = 0 ; i < n ; i++){
            if(seen[nums[i]]){
                result.push_back(nums[i]);
            }else {
                seen[nums[i]] = true;
            }
        }
        return result;
    }
};