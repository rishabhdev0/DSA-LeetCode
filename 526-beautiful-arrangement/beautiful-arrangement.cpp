class Solution {
private:
    void backtracking(int n, int pos, vector<bool>& visited, int& count) {
        if (pos > n) {
            count++;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) { // not visited 
                visited[i] = true; // mark as viisted
                backtracking(n, pos + 1, visited, count); // look for another pos
                visited[i] = false; // backtrack
            }
        }
    }
    
public:
    int countArrangement(int n) {
        int count = 0;
        vector<bool> visited(n + 1, false); // 1-based indexed
        backtracking(n, 1, visited, count);
        return count;
    }
};