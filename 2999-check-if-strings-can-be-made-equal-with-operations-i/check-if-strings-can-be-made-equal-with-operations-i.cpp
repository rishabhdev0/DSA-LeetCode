class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.length();
        // vector<bool> used(n, false);

        for(int i = 0; i < n; i++) {
            bool found = false;

            for(int j = 0; j < n; j++) {
                if(  s1[i] == s2[j]) {
                    // same parity instead of abs(i-j)==2
                    if(i % 2 == j % 2) {
                         // used[j] = true;
                        found = true;
                        break;
                    }
                }
            }

            if(!found) return false;
        }

        return true;
    }
};