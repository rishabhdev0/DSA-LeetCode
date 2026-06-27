class Solution {
public:
    bool isNotEqual(string &a , string &b){
        int freq[26] = {0};

        for(char ch : a){
            freq[ch - 'a']++;
        }

       for(char ch : b){
          if(freq[ch - 'a'] > 0) return false;
          freq[ch - 'a']++;
       }
       return true;
    }
    int solve(vector<string>& arr , string temp ,  int idx){
        if(idx == arr.size()){
            return temp.size();
        }
        int take = 0;

        if(isNotEqual(temp , arr[idx])){
            take = solve(arr , temp + arr[idx] , idx + 1);
        }

        int not_take = solve(arr , temp , idx + 1);

        return max(take , not_take);
    }
    int maxLength(vector<string>& arr) {
        return solve(arr , "" , 0); 
    }
};