class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.length();
        unordered_set<string>seen;
        vector<string>result;
        int start = 0;
        while(start < n){
            int end = start + 1;
            while(end <= n){
               string sub = s.substr(start , end - start);
                 if(seen.count(sub) == 0){
                     seen.insert(sub);
                     result.push_back(sub);
                     break;
                 }
                 end++;
            }
            start = end;
        }
        return result;
    }
};