class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int ones_cnt = 0;
        int j = 0;
        string result = "";
        while(j < n ){
            if(s[j] == '1'){
                ones_cnt++;
            }
            while(ones_cnt > k){
                if(s[i] == '1'){
                    ones_cnt--;
                }
                i++;
            }

            if(ones_cnt == k){
                while(i <= j && s[i] == '0'){
                    i++;
                }
                string temp = s.substr(i , j - i + 1);
                if(result.empty() || temp.size() < result.size() || (temp.size() == result.size() &&
                temp < result)){
                    result = temp;
                }
            }
            j++;
        }
        return result;
    }
};