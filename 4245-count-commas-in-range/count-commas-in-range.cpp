class Solution {
public:
    int countCommas(int n) {
        int diff  =  n - 999;
        if(diff > 0) return diff;
        else return 0;
    }
};