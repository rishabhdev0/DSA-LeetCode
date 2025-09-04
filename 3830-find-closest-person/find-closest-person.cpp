class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff_a = abs(z - x);
        int diff_b = abs(z-y);
        if(diff_a < diff_b) return 1;
        else if(diff_a > diff_b) return 2;
        else return 0;
    }
};