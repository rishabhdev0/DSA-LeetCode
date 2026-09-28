class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int result = 0;
        for(char ch : s){
            if(ch == '('){
                open++;
                result = max(result , open);
            }else if(ch == ')'){
                open--;
            }
        }
        return result;
    }
};