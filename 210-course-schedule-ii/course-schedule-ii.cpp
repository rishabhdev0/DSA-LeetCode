// class Solution {
// private:
//     bool dfs(int node, vector<bool>& visited, vector<bool>& inRecursion, vector<vector<int>>& graph, vector<int>& result) {
//         visited[node] = true;
//         inRecursion[node] = true;
//         for(auto neighbor : graph[node]) {
//             if(!visited[neighbor]) {
//                 if(dfs(neighbor, visited, inRecursion, graph, result)) {
//                     return true;
//                 }
//             }
//             else if(inRecursion[neighbor]) {
//                 return true; 
//             }
//         }
//         inRecursion[node] = false; // Backtrack
//         result.push_back(node); // Post-order
//         return false;
//     }
    
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> graph(numCourses);
//         vector<bool> visited(numCourses, false);
//         vector<bool> inRecursion(numCourses, false);
//         vector<int> result;
        
//         for(auto &pre : prerequisites) {
//             graph[pre[1]].push_back(pre[0]);
//         }
        
//         for(int i = 0; i < numCourses; i++) {
//             if(!visited[i]) {
//                 if(dfs(i, visited, inRecursion, graph, result)) {
//                     return {}; 
//                 }
//             }
//         }
//         reverse(result.begin(), result.end());
//         return result;
//     }
// };


// breadth first search;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        for(auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            // Process neighbors
            for(int neighbor : graph[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if(result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
    }
};

