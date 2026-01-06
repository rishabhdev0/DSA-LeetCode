class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int i = 0;
        int ans = 1;

        for(int j = 0; j < nums.size(); j++){

            maxHeap.push({nums[j], j});
            minHeap.push({nums[j], j});

            while(maxHeap.top().first - minHeap.top().first > limit){

                i++;   
               
                while(maxHeap.top().second < i)
                    maxHeap.pop();

                while(minHeap.top().second < i)
                    minHeap.pop();
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
