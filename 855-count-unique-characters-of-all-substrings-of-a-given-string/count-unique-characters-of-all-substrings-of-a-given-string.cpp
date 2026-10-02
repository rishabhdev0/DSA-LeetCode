class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        int count = 0;

        vector<vector<int>> freq(26);

        for(char ch = 'A'; ch <= 'Z'; ch++) {
            for(int i = 0; i < n; i++) {
                if(ch == s[i]) {
                    freq[ch - 'A'].push_back(i);
                }
            }
        }

        for(char ch = 'A'; ch <= 'Z'; ch++) {
            vector<int>& position = freq[ch - 'A'];

            for(int i = 0; i < position.size(); i++) {

                int prev = (i == 0) ? -1 : position[i - 1];
                int curr = position[i];
                int next = (i == position.size() - 1) ? n : position[i + 1];

                int sum = (curr - prev) * (next - curr);

                count += sum;
            }
        }

        return count;
    }
};