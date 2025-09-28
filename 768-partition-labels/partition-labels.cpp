class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>result;
        vector<int> freq(26 , -1);
       // last index
        for(int i = 0 ; i<n;i++){
           freq[s[i] - 'a'] = i;
        }
       int i = 0;
        while(i<n){
            int last_idx = freq[s[i]-'a'];
            int j = i;
            while(j<last_idx){
                last_idx = max(last_idx , freq[s[j]-'a']);
                j++;
            }
            result.push_back(j-i+1);
            i = j+1;
        }
        return result;
    }
};