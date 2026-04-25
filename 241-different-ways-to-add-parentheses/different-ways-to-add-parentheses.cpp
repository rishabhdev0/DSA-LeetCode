class Solution {
public:
   unordered_map<string , vector<int>>dp;

    vector<int> solve(string expression) {
      
      if(dp.count(expression)){
        return dp[expression];
      }

        vector<int> result;

        for (int i = 0; i < expression.size(); i++) {
            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = solve(expression.substr(0, i));
                vector<int> right = solve(expression.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') {
                            result.push_back(l + r);
                        } else if (ch == '-') {
                            result.push_back(l - r);
                        } else {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        if (result.empty()) { // suppose no expression is present
            result.push_back(stoi(expression));
        }

        return dp[expression] = result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};