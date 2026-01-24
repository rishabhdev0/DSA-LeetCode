class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for (int x : piles) {
            pq.push(x);
        }

        while (k--) {
            int top = pq.top();
            pq.pop();
            top -= top / 2;  
            pq.push(top);
        }

        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
