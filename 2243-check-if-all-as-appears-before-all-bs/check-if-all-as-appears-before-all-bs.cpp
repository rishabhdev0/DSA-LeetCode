class Solution {
public:
    bool checkString(string s) {
        int count_a = count(s.begin() , s.end() , 'a');
        int count_b = s.length() - count_a;
        if(count_a == 0 || count_b == 0) return true;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'b'){
               if(count_a > 0) return false;
            }else{
                count_a--;
            }
        }
        return true;
    }
};