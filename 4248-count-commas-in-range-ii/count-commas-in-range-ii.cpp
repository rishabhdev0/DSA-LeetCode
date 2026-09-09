class Solution {
public:
    long long countCommas(long long n) {
        long long answer = 0;
        int commas = 1;
        for(long long start = 1000 ; start <= n ; start *= 1000){
            answer += n - start + 1;
        }
        return answer;
    }
};