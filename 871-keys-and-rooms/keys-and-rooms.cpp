// class Solution {
// private:
//     void dfs(int source, vector<vector<int>>& rooms, vector<bool>& visited) {
//         visited[source] = true;
//         for(auto neighbor : rooms[source]) {
//             if(!visited[neighbor]) {
//                 dfs(neighbor, rooms, visited);
//             }
//         }
//     }
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n = rooms.size();
//         vector<bool> visited(n, false);
//         dfs(0, rooms, visited);
//         for(int i = 0; i < n; i++) {
//             if(visited[i] == false) return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            
            for (int neighbor : rooms[room]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // Check if all rooms are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};