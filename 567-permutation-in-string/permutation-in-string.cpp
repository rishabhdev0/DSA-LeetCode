class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int k = s2.length();
        if (n > k) return false; //edge case s1 cant bigger than s2

        vector<int> freq(26, 0);
        vector<int> windowfreq(26, 0);

        // freq of s1
        for (char &ch : s1) {
            freq[ch - 'a']++;
        }

        int i = 0;
        int j = 0;
        while (j < k) {
            windowfreq[s2[j] - 'a']++; // current element to the window

          // shrinking the window move the i pointer
            if (j - i + 1 > n) {
                windowfreq[s2[i] - 'a']--; // remove the ith charcter 
                i++;
            }

            // condition check
            if (j - i + 1 == n && freq == windowfreq) {
                return true;
            }

            j++;
        }

        return false;
    }
};