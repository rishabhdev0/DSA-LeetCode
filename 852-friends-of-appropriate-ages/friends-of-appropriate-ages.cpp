class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin() , ages.end());
        int answer = 0;
        for(int age : ages){
            int lowerBound = age / 2 + 7;
            auto low = upper_bound(ages.begin() , ages.end() , lowerBound);
            auto high = upper_bound(ages.begin() , ages.end() , age);
            int cnt = high - low;
            if(cnt > 0){
                answer += cnt - 1; // exclude itself;
            }
        }
        return answer;
    }
};