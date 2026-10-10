class Solution {
public:
    int result = 1;

    int dfs(vector<vector<int>>& adj , int parent , int node , string& s){
        int longest = 0;
        int second_longest = 0;

        for(auto& child : adj[node]){
            if(child == parent) continue;

            int child_longest_length = dfs(adj , node , child , s);

            if(s[child] == s[node]) continue;

            // now find the largest and second largest;
            if(child_longest_length > longest){
                second_longest = longest;
                longest = child_longest_length;
            }else if(child_longest_length > second_longest){
               second_longest = child_longest_length;
            }
        }
        int only_one_better = longest + 1; // node itself;
        int found_answer_lower = longest + second_longest + 1;

        result = max(result ,found_answer_lower);

        return only_one_better;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>adj(n);
        for(int i = 1 ; i < n ; i++){
            int u = i;
            int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj , -1 , 0 , s);
        return result;
    }
};