class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> result(n);
        
        int prev = -10000;  
        
        // Left to Right pass
        for(int i = 0; i < n; i++){
            if(s[i] == c){
                prev = i;
            }
            result[i] = i - prev;
        }
        
        prev = INT_MAX; 
        
        // Right to Left pass
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == c){
                prev = i;
            }
            result[i] = min(result[i], prev - i);
        }
        
        return result;
    }
};