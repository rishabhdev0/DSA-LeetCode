class Solution {
public:
    int strStr(string haystack, string needle) {
        int n =  haystack.length();
        int m = needle.length();
        for(int j = 0 ; j <= n - m ; j++){
            int i = 0;
            while(i < m && haystack[j+i] == needle[i]){
                i++;
            }
            if(i == m){
                return j;
            }
        }
        return -1;
    }
};