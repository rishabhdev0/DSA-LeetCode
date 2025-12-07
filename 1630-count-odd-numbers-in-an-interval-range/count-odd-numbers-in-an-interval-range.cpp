class Solution {
public:
    int countOdds(int low, int high) {
        // case 1 -> both are odd
        if(low % 2 == 0 && high % 2 == 0){
           int mid = (high - low)/2;
           return mid;
        }else {
            int mid = (high - low )/2;
            return mid + 1;
        }
        return -1;
    }
};