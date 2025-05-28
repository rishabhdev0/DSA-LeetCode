class Solution {
public:
    bool isValid(unordered_map<char, int>& freq, int k) {
        for (auto& entry : freq) {
            if (entry.second < k)
                return false;
        }
        return true;
    }

    int takeCharacters(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }
        
         if (freq['a'] < k || freq['b'] < k || freq['c'] < k) {
            return -1;
        }

        if (!isValid(freq, k))
            return -1;

        int i = 0, j = 0;
        int window_size = 0;
        unordered_map<char, int> temp = freq;

        while (j < n) {
            temp[s[j]]--;

            while (i <= j && !isValid(temp, k)) {
                temp[s[i]]++;
                i++;
            }

            window_size = max(window_size, j - i + 1);
            j++;
        }

        return n - window_size;
    }
};
