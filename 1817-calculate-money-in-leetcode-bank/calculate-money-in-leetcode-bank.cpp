class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int week = 0;
        int day = 0;
        for(int i = 0 ; i < n ; i++){
            if(i % 7 == 0){
                week++;  // at each new week we add extra 1 value every time
                day = 1; // restart 
            }else day++;
            total +=(week + day - 1);
        }
        return total;
    }
};