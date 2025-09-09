class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int total = tasks.size();          
        vector<int> freq(26, 0);

        for (int i = 0; i < total; ++i) {
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0){
               pq.push(freq[i]);
            } 
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;

            // schedule up to (n + 1) tasks this cycle
            for (int i = 0; i <= n; ++i) {
                if (!pq.empty()) {
                    int top = pq.top();
                    pq.pop();
                    top--;
                    if (top > 0) temp.push_back(top);
                    // we executed a task in this slot
                    time++;
                } else {
                    // no task to execute: idle slot
                    // if there are no pending tasks in temp, we can stop early
                    if (temp.empty()) break;
                    time++;
                }
            }

            // push remaining (decremented) frequencies back into pq
            for (int f : temp) pq.push(f);
        }
 
        return time;
    }
};
