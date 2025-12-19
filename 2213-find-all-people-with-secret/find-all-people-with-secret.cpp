class Solution {
public:
    typedef pair<int,int> p;

    // DFS: spread the secret in the graph of this timestamp
    void dfs(int person, unordered_map<int, vector<int>>& adj, vector<bool>& knowSecret) {
        knowSecret[person] = true;

        for (int i = 0; i < adj[person].size(); i++) {
            int neighbor = adj[person][i];
            if (!knowSecret[neighbor]) {
                dfs(neighbor, adj, knowSecret);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Map: time -> list of meetings at that time
        map<int, vector<p>> meetingTime;
        for (int i = 0; i < meetings.size(); i++) {
            int first_person = meetings[i][0];
            int second_person = meetings[i][1];
            int time = meetings[i][2];
            meetingTime[time].push_back({first_person, second_person});
        }

        vector<bool> knowSecret(n, false);
        knowSecret[0] = true;
        knowSecret[firstPerson] = true;

        // Process meetings time by time
        for (auto it = meetingTime.begin(); it != meetingTime.end(); it++) {
            vector<p> meetingsAtThisTime = it->second;

            // Build adjacency list for this timestamp
            unordered_map<int, vector<int>> adj;
            for (int i = 0; i < meetingsAtThisTime.size(); i++) {
                int personOne = meetingsAtThisTime[i].first;
                int personTwo = meetingsAtThisTime[i].second;
                adj[personOne].push_back(personTwo);
                adj[personTwo].push_back(personOne);
            }

            // DFS from all people who already know the secret
            for (auto it = adj.begin(); it != adj.end(); it++) {
                int person = it->first;
                if (knowSecret[person]) {
                    dfs(person, adj, knowSecret);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knowSecret[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
