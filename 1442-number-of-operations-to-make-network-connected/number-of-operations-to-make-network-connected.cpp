class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y) { 
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int extraCables = 0;  
        int components = n;   
        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if (parent_u == parent_v) {
                // extra
                extraCables++;
            } else {
                // Connect the components
                unionSet(u, v);
                components--;
            }
        }
        int neededCables = components - 1;
        if (extraCables >= neededCables) {
            return neededCables;
        } else {
            return -1;
        }
    }
};