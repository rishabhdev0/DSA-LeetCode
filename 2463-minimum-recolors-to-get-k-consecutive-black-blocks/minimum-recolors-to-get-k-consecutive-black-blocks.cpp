class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int count_white = 0;

        for(int i = 0; i < k; i++) {
            if(blocks[i] != 'B') {
                count_white++;
            }
        }

        int i = 0;
        int j = k;
        int min_count = count_white;

        while(j < n) {
            if(blocks[i] != 'B') count_white--; 
            if(blocks[j] != 'B') count_white++;
            min_count = min(min_count, count_white);
            i++;
            j++;
        }

        return min_count;
    }
};
