class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string result  = "";
        for(char ch : s){
            if(ch == '('){
                if(open != 0){
                    result += ch;
                }
                open++;
            }else{
                open--;
                if(open != 0){
                    result += ch;
                }
            }
        }
        return result;
    }
};