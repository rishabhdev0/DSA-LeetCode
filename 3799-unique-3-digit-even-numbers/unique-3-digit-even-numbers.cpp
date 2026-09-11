class Solution {
public:
    vector<int>temp;
    unordered_set<int>seen;
    vector<bool> used;
    void solve(vector<int>& digits){
        if(temp.size() == 3){
            if(temp[2] % 2 == 0){
                int num = temp[0] * 100 + temp[1] * 10 + temp[2];
                seen.insert(num);
            }
            return;
        }


        for(int  i = 0 ; i < digits.size() ; i++){
            if(used[i]) continue;
            if(temp.size() == 0 && digits[i] == 0) continue;
            used[i] = true;
            temp.push_back(digits[i]);
            solve(digits);
            temp.pop_back();
            used[i] =  false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        used.assign(digits.size() , false);
        solve(digits);
        return seen.size();
    }
};