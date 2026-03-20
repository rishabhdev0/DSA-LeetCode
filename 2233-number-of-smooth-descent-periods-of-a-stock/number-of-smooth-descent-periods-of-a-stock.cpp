class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long answer = 0;
        int i = 0;

        for(int j = 0; j < n; j++){
            if(j > 0 && prices[j] - prices[j-1] != -1){
                i = j;
            }
            answer += (j - i + 1);
        }
        return answer;
    }
};