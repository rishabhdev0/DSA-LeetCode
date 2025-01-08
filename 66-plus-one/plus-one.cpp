class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
     for(int i=n-1;i>=0;--i){
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }

        // if the last element is 0 then we check and insert the +1 in the front for example 999 = last digit is 9 +1=0 then in the front we will insert 1 it will become 1000
        
             digits[i]=0;
        
        
     }    
     digits.insert(digits.begin(),1);

     return digits;
    }

};