class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        vector<int>freq(26 , 0);
        for(char ch : text){
            freq[ch - 'a']++;
        }
        int maxLen = 1;

        for(char ch = 'a' ; ch <= 'z' ; ch++){
            int i = 0;
            int different = 0;
            int j = 0;
            while(j < n){
                if(text[j] != ch){
                    different++;
                }
                while(different > 1){
                    if(text[i] != ch){
                        different--;
                    }
                    i++;
                }
                int len = j - i + 1;
                maxLen = max(maxLen , min(len , freq[ch - 'a']));
                j++;
            }
        }
        return maxLen;
    }
};