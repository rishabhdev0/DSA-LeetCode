class Solution {
public:
    bool isPowerOfThree(int n) {
      for(int i =  0 ; i < 20; i++){
        int equal = pow(3 , i);
        if(equal == n) return true;
      }  
      return false;
    }
};