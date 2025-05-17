class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int j = sqrt(c);
        while(i <= j){ 
            long long target = (long long)i * i + (long long)j * j; 
            if(target == c){
                return true;
            } else if (target < c){
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};
