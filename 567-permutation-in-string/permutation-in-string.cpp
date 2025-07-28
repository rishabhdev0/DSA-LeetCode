class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) return false; //edge case s1 cant bigger than s2

        vector<int> freq(26, 0);
        vector<int> windowfreq(26, 0);

        // freq of s1
        for (char &ch : s1) {
            freq[ch - 'a']++;
        }

        int i = 0;
        int j = 0;
        while (j < m) {
            windowfreq[s2[j] - 'a']++; // current element to the windowfreq

            if (j - i + 1 > n) {
                windowfreq[s2[i] - 'a']--; // remove the ith charcter 
                i++;
            }

           // freq must be equal  to window so that all char matched
            if (j - i + 1 == n && freq == windowfreq) {
                return true;
            }

            j++;
        }

        return false;
    }
};