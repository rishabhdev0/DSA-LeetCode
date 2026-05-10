class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string,int> mp;
        int ans = 0;

        for(string word : words){

            string rev = word;
            reverse(rev.begin(), rev.end());

            // reverse word already exists
            if(mp[rev] > 0){

                ans += 4;
                mp[rev]--;
            }
            else{
                mp[word]++;
            }
        }

        // check center possible
        for(auto it : mp){

            string s = it.first;

            if(s[0] == s[1] && it.second > 0){
                ans += 2;
                break;
            }
        }

        return ans;
    }
};