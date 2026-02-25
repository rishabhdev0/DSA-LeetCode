class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int openCount = 0;
        int ops = 0;
        for(char ch : s){
            if(ch == '('){
                openCount++;
            }else{
                if(openCount > 0){
                    openCount--;
                }else{
                    ops++;
                }
            }
        }
        ops += openCount;
        return ops;
    }
};