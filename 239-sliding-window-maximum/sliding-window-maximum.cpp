class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;
        int i = 0;
        int j = 0;
        while(j < nums.size()){
            while(!dq.empty() && dq.front() <= j - k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j >= k -1){
                result.push_back(nums[dq.front()]);
            }
            j++;
        }
        return result;
    }
};