class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if(events.empty()) return 0;
        int n = events.size();
        sort(events.begin() , events.end());
        int answer = 0 ;
        int day = events[0][0]; // for day 
        int i = 0; // for looping
        priority_queue<int, vector<int>, greater<int>>pq; // stores end time;

        while(i < n || !pq.empty()){
           while(i <  n && events[i][0] <= day){
                 pq.push(events[i][1]); // only stores the  end time
                 i++;
           }
           // pop the days that already has the within day so no need to compute them
           while(!pq.empty() && pq.top() < day){
             pq.pop();
           }
           if(!pq.empty()){
            pq.pop();
            answer++;
            day++;
           }else if(i < n){
              day = events[i][0]; // to keep back to the day where it work
           }
        }
      return answer;
    }
};