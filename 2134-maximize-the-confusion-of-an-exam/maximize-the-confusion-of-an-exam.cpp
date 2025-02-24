class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // case 1 converting all FALSE into TRUE
        int n=answerKey.length();
        int i=0;
        int j=0;
        int count_false=0;
        int result =0;
        while(j<n){
            if(answerKey[j]=='F'){
                count_false++;
            }
            while(count_false > k){
                if(answerKey[i]=='F'){
                    count_false--;
                }
                i++;
            }
            result = max(result , j-i+1);
            j++;
        }
        // case 2 true into false
         i = 0;
         j = 0;
        int count_true=0;
         while(j<n){
            if(answerKey[j]=='T'){
                count_true++;
            }
            while(count_true > k){
                if(answerKey[i]=='T'){
                    count_true--;
                }
                i++;
            }
            result = max(result , j-i+1);
            j++;
        }
         return result;
    }
};