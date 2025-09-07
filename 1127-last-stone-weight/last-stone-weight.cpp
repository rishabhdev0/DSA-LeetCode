class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(nums[i]);
        }
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int destroyed = first - second;
            pq.push(destroyed);
        }
        return pq.top();
    }
};