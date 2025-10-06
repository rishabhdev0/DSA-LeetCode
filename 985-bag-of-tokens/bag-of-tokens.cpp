#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = (int)tokens.size() - 1;
        int score = 0;       
        int best = 0;        

        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                ++score;
                best = max(best, score);
            }
            // we have at least 1 score, sell the largest token
            else if (score > 0) {
                power += tokens[j--]; 
                --score;
            } else { // cannot buy and cannot sell 
                break;
            }
        }
        return best; 
    }
};
