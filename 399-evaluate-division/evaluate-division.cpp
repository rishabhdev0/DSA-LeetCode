class Solution {
public:
    double dfs(string node, string target, unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited, double current) {
        
        if (node == target) return current;
        visited.insert(node);
        
        for (auto& [neighbor, weight] : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                double result = dfs(neighbor, target, graph, visited, current * weight);
                if (result != -1.0) return result;
            }
        }
        
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, 
                                vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0 / val});
        }
        
        vector<double> results;
        
        for (auto& query : queries) {
            string src = query[0];
            string dest = query[1];
            
            // If either node doesn't exist
            if (graph.find(src) == graph.end() || graph.find(dest) == graph.end()) {
                results.push_back(-1.0);
                continue;
            }
            
            unordered_set<string> visited;
            double result = dfs(src, dest, graph, visited, 1.0);
            results.push_back(result);
        }
        
        return results;
    }
};