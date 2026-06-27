class Solution {
public:
    vector<string>result;
    string temp = "";

    void solve(string &s , int idx){
        if(idx == s.length()){
            result.push_back(temp);
            return;
        }
        char ch = s[idx];

        if(isdigit(ch)){
            temp.push_back(ch);
            solve(s , idx + 1);
            temp.pop_back();
        }else{
            // to cases 1. make it lower;
            temp.push_back(tolower(ch));
            solve(s , idx + 1);
            temp.pop_back();

            // case 2 .  make it upper;
            temp.push_back(toupper(ch));
            solve(s , idx + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        solve(s , 0);
        return result;
    }
};