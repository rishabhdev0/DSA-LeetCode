class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops_count = 0;
        while(num1 != 0 && num2 != 0){  
            if(num1 >= num2){
                num1 = num1 - num2;  
            } else {
                num2 = num2 - num1;  
            }
            ops_count++;
        }
        return ops_count;
    }
};