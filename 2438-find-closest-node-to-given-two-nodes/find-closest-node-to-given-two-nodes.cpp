class Solution {
public:
    int n;
    void dfs(vector<int>& edges , int node , vector<int>& dist , vector<bool>& visited){
        visited[node] = true;
        int next_node = edges[node];
        if(next_node != -1 && !visited[next_node]){
            visited[next_node] = true;
            dist[next_node] = 1 + dist[node];
            dfs(edges , next_node , dist , visited);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int>dist_1(n , INT_MAX);
        vector<int>dist_2(n , INT_MAX);

        vector<bool>visited1(n , false);
        vector<bool>visited2(n , false);

        dist_1[node1] = 0;
        dist_2[node2] = 0;

        dfs(edges , node1 , dist_1 , visited1);
        dfs(edges , node2 , dist_2 , visited2);

        int minDist = -1;
        int min_dist_till_now = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int maxD = max(dist_1[i] , dist_2[i]);
            if(min_dist_till_now > maxD){
                min_dist_till_now= maxD;
                minDist = i;
            }
        }
        return minDist;
    }
};