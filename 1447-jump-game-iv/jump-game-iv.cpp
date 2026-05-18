class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , vector<int>>freq;

       for(int i = 0 ; i < n ; i++){
        freq[arr[i]].push_back(i);
       }

        queue<int>que;
        vector<bool>visited(n , false);
        que.push(0);
        visited[0] = true;
        int steps = 0;

        while(!que.empty()){
            int size = que.size();
            while(size --){
            int top = que.front();
            que.pop();

            if(top == n -1) return steps;

            if(top - 1 >= 0 && !visited[top - 1]){
                que.push(top-1);
                visited[top - 1] = true;
            }

            if(top + 1 < n && !visited[top + 1]){
                que.push(top + 1);
                visited[top + 1];
            }

            if(freq.find(arr[top]) != freq.end()){
                for(int next : freq[arr[top]]){
                    if(!visited[next]){
                       visited[next] = true;
                       que.push(next);
                    }
                }
                freq.erase(arr[top]);
            }
        }   
            steps++;
        }
        return steps;
    }
};