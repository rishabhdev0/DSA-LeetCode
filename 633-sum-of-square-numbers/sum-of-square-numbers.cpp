class Solution {
public:
    bool judgeSquareSum(int c) {
         int start = 0;
         int end = sqrt(c);
         while(start <= end){
            long long target = (long long)start * start + (long long) end * end;
            if(target == c) return true;
            
            else if(target > c){
                end --;
            }else start ++;
        }
        return false;
    }
};