class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int> P;   // {endTime , roomIndex}

    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        // min-heap of available room indices
        priority_queue<int, vector<int>, greater<int>> available;

        // min-heap of rooms currently in use: {endTime , roomIndex}
        priority_queue<P, vector<P>, greater<P>> used;

        vector<int> roomCount(n, 0);

        for(int i = 0; i < n; i++) available.push(i);

        for(auto &meet : meetings){

            ll start = meet[0];
            ll end   = meet[1];
            ll duration = end - start;

            // free rooms whose meeting already ended
            while(!used.empty() && used.top().first <= start){
                available.push(used.top().second);
                used.pop();
            }

            int room;

            if(!available.empty()){
                // assign the smallest indexed free room
                room = available.top();
                available.pop();

                used.push({end, room});
            }
            else{
                // delay meeting until earliest room is free
                auto top = used.top();
                used.pop();

                ll newEnd = top.first + duration;
                room = top.second;

                used.push({newEnd, room});
            }

            roomCount[room]++;
        }

        int ans = 0;
        for(int i = 1; i < n; i++){
            if(roomCount[i] > roomCount[ans])
             ans = i;
        }

        return ans;
    }
};
