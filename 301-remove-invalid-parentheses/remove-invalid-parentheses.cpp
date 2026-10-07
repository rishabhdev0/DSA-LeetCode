class Solution {
public:
    unordered_set<string>st;
    string temp;
    int n;
    int maxLen = 0;

    void solve(string& s , int idx , int open){
       if(open < 0) return;
       if(idx == n){
          if(open == 0){
             if(temp.length() > maxLen){
                maxLen = temp.length();
                st.clear();
                st.insert(temp);
             }else if(temp.length() == maxLen){
                st.insert(temp);
             }
          }
          return;
       }

       solve(s , idx + 1 , open); // remove
       temp.push_back(s[idx]); // take

       if(s[idx] == '('){
        solve(s , idx + 1 , open + 1);
       }else if(s[idx] == ')'){
         solve(s , idx + 1 , open - 1);
       }else{
        solve(s , idx + 1 , open);
       }
       temp.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        solve(s , 0 , 0);
        vector<string>result;
        for(auto x : st){
            result.push_back(x);
        }
        return result;
    }
};