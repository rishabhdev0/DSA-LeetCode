class Solution {
public:
    vector<string>result;
    string temp;

    void solve(int n , int open , int closed){
        if(temp.size() == 2 * n){
            result.push_back(temp);
        }
        if(open < n){
             temp.push_back('(');
             solve(n , open + 1 , closed);
             temp.pop_back();
        }
        if(closed < open){
           temp.push_back(')');
           solve(n , open , closed + 1);
           temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n , 0 , 0);
        return result;
    }
};