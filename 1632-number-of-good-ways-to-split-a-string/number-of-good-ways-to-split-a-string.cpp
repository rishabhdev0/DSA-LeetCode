class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        unordered_set<char>seen;
        vector<int>right_freq(n);
        for(int i = n - 1 ; i >= 0 ; i--){
            seen.insert(s[i]);
            right_freq[i] = seen.size();
        }
        seen.clear();
        int answer = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            seen.insert(s[i]);
            int left = seen.size();
            int right = right_freq[i + 1];
            if(left == right) answer++;
        }
        return answer;
    }
};