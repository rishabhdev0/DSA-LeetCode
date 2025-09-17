class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        unordered_set<int>seen(nums.begin() , nums.end());
        int count = 0 ;
        int current = 1;
        while(true){
            if(seen.count(current)==0){
                count++;
                if(count==k) return current;
            } 
            current++;
        }
        return -1;
    }
};