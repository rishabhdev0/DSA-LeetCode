class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;

        for(int i = 0 ; i < n - 1 ; i++){
            if(heights[i] >= heights[i+1]) continue;
            int climb = heights[i+1] - heights[i];
            bricks -= climb;
            pq.push(climb);

            if(bricks < 0){
                if(ladders > 0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }else{
                    return i;
                }
            }
        }
        return n - 1;
    }
};