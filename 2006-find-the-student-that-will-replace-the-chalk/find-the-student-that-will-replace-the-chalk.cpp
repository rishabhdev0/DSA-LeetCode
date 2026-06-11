class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long sum = accumulate(chalk.begin() , chalk.end() , 0LL);
       int target = k % sum;
       for(int i = 0 ; i < chalk.size() ; i++){
         if(target < chalk[i]){
            return i;
         }
         target -= chalk[i];
       }
       return 0;
    }
};