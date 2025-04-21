class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> answer;
        // last occurrence of each character
        vector<int> mp(26, -1);
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            mp[idx] = i;
        }
        
        int i = 0;
        while(i < n) {
            int end = mp[s[i] - 'a']; // assign the last index  
            int j = i;
            while(j < end) {
                end = max(end, mp[s[j] - 'a']);// updated last occurance
                j++;
            }
            answer.push_back(j - i + 1);
            i = j + 1;
        }
        return answer;
    }
};