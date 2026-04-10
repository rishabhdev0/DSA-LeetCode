// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses); // adjacency list
//         vector<int> indegree(numCourses, 0); 
//         for(auto &pre : prerequisites) {
//             int a = pre[0];
//             int b = pre[1]; 
//             adj[b].push_back(a);
//             indegree[a]++;
//         }
        
//         int count = 0;
//         queue<int> q;
//         for(int i = 0; i < numCourses; i++) {
//             if(indegree[i] == 0) {
//                 q.push(i);
//             }
//         }
//         while(!q.empty()) {
//             int node = q.front();
//             q.pop();
//             count++;
//             for(int &neighbor : adj[node]) {
//                 indegree[neighbor]--;
//                 if(indegree[neighbor] == 0) {
//                     q.push(neighbor);
//                 }
//             }
//         }
//         return count == numCourses;
//     }
// };
class Solution {
private:
    bool isCycle(int node, vector<bool>& visited, vector<bool>& inRecursion, unordered_map<int, vector<int>>& adj) {
        visited[node] = true;
        inRecursion[node] = true;
        
        for(int &neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(isCycle(neighbor, visited, inRecursion, adj)) {
                    return true;
                }
            }
            else if(inRecursion[neighbor]) {
                return true; 
            }
        }
        
        inRecursion[node] = false; 
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        for(auto &pre : prerequisites) {
            int a = pre[0]; 
            int b = pre[1]; 
            adj[b].push_back(a);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(isCycle(i, visited, inRecursion, adj)) {
                    return false; 
                }
            }
        }
        return true; // No cycles - can finish
    }
};