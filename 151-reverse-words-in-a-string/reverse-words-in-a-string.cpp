class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
       for(int i = n - 1 ; i>=0 ; i --){
        while(i >= 0 &&  s[i] == ' '){
            i--;
        }
        
         if(i < 0)
                break;
            
          int j = i;
          while(j >= 0 && s[j] != ' '){
             j--;
          }
          string sub = s.substr(j+1 , i - j);
          result += sub;
          result += ' ';
          i = j;
       }

       if(!result.empty()){
        result.pop_back();
       }

       return result;
    }
};