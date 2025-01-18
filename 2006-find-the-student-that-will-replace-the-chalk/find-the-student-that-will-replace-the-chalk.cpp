class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int  total=0;
        for(int i:chalk){
            total+=i;
        }
        k=k%total;
        for(int j=0;j<chalk.size();j++){
            k-=chalk[j];
            if(k<0){
             return j;
            }
        }
        return -1;
    }
};