class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long swap_count = 0;
        long long one_count = 0;
        for(int i = 0 ; i<n;i++){
            if(s[i]=='1'){
                one_count++;
            }else{
                swap_count+=one_count;
            }
        }
        return swap_count;
    }
};