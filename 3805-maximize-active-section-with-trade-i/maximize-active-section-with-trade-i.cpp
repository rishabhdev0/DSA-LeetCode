class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalOnes = 0;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                originalOnes++;
            }
        }

        vector<int>Zero_block;
        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                int start = i;
            while(i < n && s[i] == '0') i++;
            Zero_block.push_back(i - start);
            }else i++;
        }
 
        int result = 0;
        for(int i = 1 ; i < Zero_block.size() ; i++){
            result = max(result , Zero_block[i] + Zero_block[i-1]);
        }
        return result + originalOnes;
    }
};