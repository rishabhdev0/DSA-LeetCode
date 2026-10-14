class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int , vector<int> , greater<int>>min_heap1;
        priority_queue<int , vector<int> , greater<int>>min_heap2;

        long long answer = 0;
        int hired = 0;
        int i = 0;
        int j =  n - 1;

        while(hired < k){
            while(min_heap1.size() < candidates && i <= j){
                min_heap1.push(costs[i]);
                i++;
            }
            while(min_heap2.size() < candidates && i <= j){
                min_heap2.push(costs[j]);
                j--;
            }
            int left = min_heap1.empty() ? INT_MAX : min_heap1.top();
            int right = min_heap2.empty() ? INT_MAX : min_heap2.top();

            if(left <= right){
                answer += left;
                min_heap1.pop();
            }else{
                answer += right;
                min_heap2.pop();
            }
            hired++;
        }
        return answer;
    }
};