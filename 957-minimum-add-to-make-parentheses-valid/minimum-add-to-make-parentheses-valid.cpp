class Solution {
public:
    int minAddToMakeValid(string s) {
       int open = 0;
       int n = s.length();
       int count = 0;
       for(int i = 0 ; i < n ; i++){
          if(s[i] == '('){
             open++;
          }else{
            if(open > 0){
                open--;
            }else count++;
          }
       } 
       return open + count;
    }
};