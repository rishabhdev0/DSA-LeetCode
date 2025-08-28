class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       int n = piles.size();
       int sum = 0;
       // make the queue
       priority_queue<int>pq;
       for(int i = 0 ; i < n ; i++){
        pq.push(piles[i]);
        sum+=piles[i];
       }  
     // now traverse till k and get the sum;
     for(int i = 1 ; i <=k ; i++){
        int max_element = pq.top();
        pq.pop();
        int remove = max_element/2;
        sum-=remove;
        max_element -= remove;
        pq.push(max_element);
     }
     return sum;
    }
};