class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int sum = 0;

            for(int j = 0; j < word.length(); j++) {
                int index = word[j] - 'a';
                sum += weights[index];
            }

            int mod = sum % 26;
            char ch = 'z' - mod;
            result.push_back(ch);
        }

        return result;
    }
};