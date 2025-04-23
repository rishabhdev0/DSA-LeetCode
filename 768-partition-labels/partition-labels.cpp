class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>result;
        vector<int> freq(26 , -1);
        // last occurances if the charcter
        for(int i = 0 ; i<n;i++){
           int idx = s[i]-'a';
            freq[idx]=i;
        }
       int i = 0;
        while(i<n){
            int end = freq[s[i]-'a']; // last occurances
            int j = i;
            while(j<end){
                end = max(end , freq[s[j]-'a']);
                j++;
            }
            result.push_back(j-i+1);
            i = j+1;
        }
        return result;
    }
};