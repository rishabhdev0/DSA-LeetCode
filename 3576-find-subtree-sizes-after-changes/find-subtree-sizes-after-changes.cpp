class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> result;
    vector<int> last;

    void dfs(int currnode, string& s, vector<int>& parent) {
        int idx = s[currnode] - 'a';

        int nearestAncestor = last[idx];
        last[idx] = currnode;

        for (auto child : adj[currnode]) {
            dfs(child, s, parent);
        }

        // Backtrack: restore previous ancestor
        last[idx] = nearestAncestor;

        int newParent = parent[currnode];

        if (nearestAncestor != -1) {
            newParent = nearestAncestor;
        }

        // add subtree size into the new parent
        if (newParent != -1) {
            result[newParent] += result[currnode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.clear();

        for (int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }

        result.assign(n, 1);
        last.assign(26, -1);

        dfs(0, s, parent);

        return result;
    }
};
