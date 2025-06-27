class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        unordered_map < char , int> freq;
        for(auto &ch : s){
            freq[ch]++;
        }
        for(int i = 0 ; i < t.length() ; i++){
            char current = t[i];
            if(freq.find(current) == freq.end() && freq[current] < 1){
                return false;
            }
            freq[current]--;
        }

      for(auto& entry : freq){
        if(entry.second!=0){
            return false;
        }
      }
      return true;

    }
};