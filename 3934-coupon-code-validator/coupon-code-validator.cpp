class Solution {
public:
    bool codeCheck(string s) {
        if(s.empty()) return false;
        for (char ch : s) {
            if (!isalnum(ch) && ch != '_')
                return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        unordered_map<string, int> priority = {
            {"electronics", 1},
            {"grocery", 2},
            {"pharmacy", 3},
            {"restaurant", 4}
        };

        vector<pair<int, string>> temp; // {priority, code}

        for (int i = 0; i < code.size(); i++) {
            if (codeCheck(code[i]) &&
                isActive[i] &&
                priority.count(businessLine[i])) {

                temp.push_back({priority[businessLine[i]], code[i]});
            }
        }

        sort(temp.begin(), temp.end());

        vector<string> result;
        for (auto &p : temp) {
            result.push_back(p.second);
        }

        return result;
    }
};
