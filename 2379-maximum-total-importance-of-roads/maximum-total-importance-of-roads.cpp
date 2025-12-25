class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        
        for(auto& road : roads) {
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
        }
        
        sort(degree.begin(), degree.end());
        
        long long totalImportance = 0;
        for(int i = 0; i < n; i++) {
            totalImportance += degree[i] * (i + 1);
        }
        
        return totalImportance;
    }
};