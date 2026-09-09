class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>lastseen(26 , 0);

        for(int  i= 0 ; i < n ; i++){
            lastseen[s[i] - 'a'] = i;
        }

        int j = 0;
        vector<int>result;

        while(j <  n){
            int max_len = lastseen[s[j] - 'a'];

            int i = j;

            while(i < max_len){
                max_len = max(max_len , lastseen[s[i] - 'a']);
                i++;
            }

            result.push_back(i - j + 1);

            j = i + 1;
           
        }
        return result;
    }
};