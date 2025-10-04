class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // Fixed spelling: deque not dequeue
        vector<int> result;
        
        for(int i = 0; i < n; i++) {  
            // Step 1: Remove elements that are out of the current window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Step 2: Maintain decreasing order in deque
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {  
                dq.pop_back();
            }
            
            // Step 3: Add current element's index
            dq.push_back(i);
            
            // Step 4: Add to result once we have a full window
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;  
    }
};