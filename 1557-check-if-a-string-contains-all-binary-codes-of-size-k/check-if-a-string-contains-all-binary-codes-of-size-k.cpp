class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        set<string>count;
        int i = 0;
        int j = 0;
        while(j < n){
            if(j - i + 1 == k){
                count.insert(s.substr(i , k));
                i++;
            }
            j++;
        }
        return count.size() == (1 << k);
    }
};