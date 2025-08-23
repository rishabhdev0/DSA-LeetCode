class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> count;
        for (int i = 0 ; i < n ; i++) {
            string temp = strs[i]; 
            sort(temp.begin(), temp.end()); 
            count[temp].push_back(strs[i]);//if temp exist we return the            vector<string> otherwise we create it , count[temp] = if in map its present or not
            // it store the {aet --> {eat , tea  ate}}
        }
    
        for (auto& it : count) { 
            result.push_back(it.second);
        }
        return result;
    }
};
