class Solution {
public:
    bool check(vector<int>& freq , vector<int>& check){
       return freq == check;
    }

    vector<int> findAnagrams(string s, string p) {
          int n = s.length();
          int m = p.length();
          vector<int>idx;

          if( m > n) return idx;

         vector<int>freq(26 , 0);
         for(int i = 0 ; i < m ; i++){
            freq[p[i] - 'a']++;
         }

         int i = 0;
         int j = 0;
         vector<int>window(26 , 0);

         while(j < n){
              window[s[j] - 'a']++;
              if(j - i + 1 > m){
                window[s[i] - 'a']--;
                i++;
              }
              if(j - i + 1 == m){
                 // check al the character matches the freq;
                 if(check(freq , window)){
                    idx.push_back(i);
                 }
              }
              j++;
         }
         return idx;
    }
};