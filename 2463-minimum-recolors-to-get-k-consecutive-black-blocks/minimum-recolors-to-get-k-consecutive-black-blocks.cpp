class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int blackCount = 0;   
        int i = 0;
        int j = 0;
        int ans = k;        

        while (j < n) {
            if (blocks[j] == 'B') {
                blackCount++;
            }

            if (j - i + 1 == k) {
                ans = min(ans, k - blackCount); 

                if (blocks[i] == 'B') {
                    blackCount--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
