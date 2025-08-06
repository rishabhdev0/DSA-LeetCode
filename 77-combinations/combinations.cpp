class Solution {
public:
    vector<vector<int>>result;
    void backtracking(int n , int k , vector<int>&temp , int idx){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        for(int i = idx ; i <= n ; i++){
            temp.push_back(i);
            backtracking(n , k , temp , i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        int index = 1;
        backtracking(n , k ,temp , index);
        return result;
    }
};