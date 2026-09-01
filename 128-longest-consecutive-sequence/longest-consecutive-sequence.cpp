class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>seen(nums.begin() , nums.end());
        int maxLen = 0;
        for(auto it : seen){
            if(!seen.count(it - 1)){
                int count = 1;
                int curr = it;
                while(seen.count(curr + 1)){
                    count++;
                    curr++;
                }
                 maxLen = max(maxLen , count);
            }
        }
        return maxLen;
    }
};