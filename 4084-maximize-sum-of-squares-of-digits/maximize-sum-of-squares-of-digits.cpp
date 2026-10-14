class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num || sum < 1) return "";
        string result = "";
        
        for(int i = 0 ; i < num ; i++){
            if(sum >= 9){
                result += '9';
                sum -= 9;
            }else{
                result += char('0' + sum);
                sum = 0;
            }
        }
        if(sum > 0) return "";
        return result;
    }
};