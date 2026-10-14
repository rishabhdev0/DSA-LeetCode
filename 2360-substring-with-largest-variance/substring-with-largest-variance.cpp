class Solution {
public:
    int largestVariance(string s) {
        vector<int>count(26 , 0);
        for(char ch : s){
            count[ch - 'a']++;
        }
        int variance = 0;

        for(char first = 'a' ; first <= 'z' ; first++){
            for(char second = 'a' ; second <= 'z' ; second++){
               if(first == second || count[first - 'a'] == 0 || count[second - 'a'] == 0) continue;
               int firstcount = 0;
               int secondcount = 0;
               bool pastsecond = false;
               for(char ch : s){
                if(ch == first){
                    firstcount++;
                }
                if(ch == second){
                    secondcount++;
                    pastsecond = true;
                }

                if(secondcount > 0){
                    variance = max(variance , firstcount - secondcount);
                }else{
                    if(pastsecond){
                        variance = max(variance , firstcount - 1);
                    }
                }
                if(secondcount > firstcount){
                    firstcount = 0;
                    secondcount = 0;
                    }
                }
            }
        }
        return variance;
    }
};