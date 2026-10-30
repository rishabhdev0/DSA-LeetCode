class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        long long answer = 0;

        for(int i = 0; i + 1 < n; i++){
            if(s[i] != s[i+1]){
                answer += min(i + 1, n - i - 1);
            }
        }

        return answer;
    }
};