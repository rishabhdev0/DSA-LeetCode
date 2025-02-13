class Solution {
    private:
    bool isvowel(char &ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        int maxcount=0;
        int count=0;
        while(j<n){
            if(isvowel (s[j])){
             count++;
            }
            if(j-i+1==k){
                maxcount = max(maxcount , count);
                if(isvowel(s[i]))
                count --;
                i++;
            }
            j++;
        }
        return maxcount;
    }
};