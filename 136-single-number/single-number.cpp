class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> freq;
        
        for(int num : nums){
            freq[num]++;
        }

        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 1){
                return nums[i];
            }
        }
        return -1;
    }
};
