class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int max_range = *max_element(nums.begin() , nums.end());
        int min_range = *min_element(nums.begin() , nums.end());
        vector<int>result;
        set<int>seen(nums.begin() , nums.end());
        for(int i =  min_range ; i <= max_range ; i++){
            if(!seen.count(i)){
                result.push_back(i);
            }
        }
        
        return result;
    }
};