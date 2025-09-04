class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(nums[i]);
        }
        // pop till kth  element
        for(int i = 0 ; i < k-1 ; i++){
            pq.pop();
        }
        // result
        return pq.top();
    }
};