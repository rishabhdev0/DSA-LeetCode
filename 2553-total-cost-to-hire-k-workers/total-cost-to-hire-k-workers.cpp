#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        long long answer = 0;
        int hired = 0;
        int i = 0;        // left pointer
        int j = n - 1;    // right pointer

        while (hired < k) {
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i]);
                i++;
            }

            while (pq2.size() < candidates && i <= j) {
                pq2.push(costs[j]);
                j--;
            }

            int leftTop = pq1.empty() ? INT_MAX : pq1.top();
            int rightTop = pq2.empty() ? INT_MAX : pq2.top();

            if (leftTop <= rightTop) {
                answer += leftTop;
                pq1.pop();
            } else {
                answer += rightTop;
                pq2.pop();
            }
            hired++;
        }
        return answer;
    }
};
