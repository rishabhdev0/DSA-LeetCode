class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int>count(3 , 0);
        for(char ch : s){
            count[ch - 'a']++;
        }
        if(count[0] < k || count[1] < k || count[2] < k){
            return -1;
        }
        int i = 0;
        int j = 0;
        int taken = n;
        while(j < n){
            count[s[j] - 'a']--;
            while(count[0] < k || count[1] < k || count[2] < k){
                count[s[i] - 'a']++;
                i++;
            }
            taken = min(taken , n - (j - i + 1));
            j++;
        }
        return taken;
    }
};