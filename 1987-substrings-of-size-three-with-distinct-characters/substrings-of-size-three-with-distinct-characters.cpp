class Solution {
    private:
    bool all_unique(const vector<int>&freq){
        int unique_count = 0;
         for(int i=0;i<26;i++){
            if(freq[i] > 1){
                return false;
            }
            
        }
        return true;
    }
public:
    int countGoodSubstrings(string s) {
        int n =s.length();
        vector<int> freq(26 , 0);
        int count =  0;
        int i = 0 ;
        int j = 0;
        int k = 3;
        while(j<n){
            char curr = s[j];
            freq[curr-'a']++;
            while(j-i+1==k){
               if(all_unique(freq)){
                count++;
               }
               freq[s[i]-'a']--;
               i++;
            }
            j++;
        }
        return count;
    }
};