// class Solution {
// public:
//     int furthestDistanceFromOrigin(string moves) {
//         int n = moves.length();
//         int left = 0;
//         int right = 0;
//         int dash = 0;
//         for(char& ch : moves){
//             if(ch == 'L') left++;
//             else if(ch == 'R') right++;
//             else dash ++;
//         }
//         return abs(left - right) + dash;
//     }
// };


// fuck it , lets use dynamic programming here;

class Solution {
public:
    int dp[51][101]; 
    int n;
    
    int solve(string& moves, int idx, int pos) {
        if(idx == n) {
            return abs(pos);
        }
        
        int shifted = pos + n; 
        
        if(dp[idx][shifted] != -1) return dp[idx][shifted];
        
        int ans = 0;
        
        if(moves[idx] == 'L') {
            ans = solve(moves, idx + 1, pos - 1);
        }
        else if(moves[idx] == 'R') {
            ans = solve(moves, idx + 1, pos + 1);
        }
        else { // '_'
            int left = solve(moves, idx + 1, pos - 1);
            int right = solve(moves, idx + 1, pos + 1);
            ans = max(left, right);
        }
        
        return dp[idx][shifted] = ans;
    }
    
    int furthestDistanceFromOrigin(string moves) {
        n = moves.length();
        memset(dp, -1, sizeof(dp));
        return solve(moves, 0, 0);
    }
};
