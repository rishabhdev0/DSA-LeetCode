class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int maxCount = 0;
        int prev = 0;
        int curr = 1;
        for(int i = 1 ; i < n ; i++){
            if(s[i-1] == s[i]){
                curr++;
            }else{
                maxCount += min(curr , prev);
                prev = curr;
                curr = 1;
            }
        }
        maxCount += min(prev , curr);
        
        return maxCount;
    }
};