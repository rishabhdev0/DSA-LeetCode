class Solution {
public:
    char dfs(unordered_map<char, vector<char>>& adj, char current, vector<int>& visited) {
        visited[current - 'a'] = 1;
        char minVal = current;

        for (auto curr : adj[current]) {
            if (!visited[curr - 'a']) {
                minVal = min(minVal, dfs(adj, curr, visited));
            }
        }
        return minVal;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        unordered_map<char, vector<char>> adj;

        for (int i = 0; i < n; i++) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result = "";

        for (int i = 0; i < m; i++) {
            char ch = baseStr[i];
            vector<int> visited(26, 0);
            char minChar = dfs(adj, ch, visited);
            result += minChar;
        }

        return result;
    }
};
