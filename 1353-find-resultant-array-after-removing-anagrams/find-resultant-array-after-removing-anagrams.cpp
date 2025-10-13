class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prev = ""; // store sorted version of previous word
        
        for (string& word : words) {
            string currWord = word;
            sort(currWord.begin(), currWord.end());
            
            // If current word is not an anagram of previous word, add to result
            if (currWord != prev) {
                result.push_back(word);
                prev = currWord;
            }
        }
        
        return result;
    }
};