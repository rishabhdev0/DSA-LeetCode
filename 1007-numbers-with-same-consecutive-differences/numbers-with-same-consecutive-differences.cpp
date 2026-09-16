class Solution {
public:
    void backtracking(int n , int k , int len , int num , vector<int>& result){
        if(len == n){
            result.push_back(num);
            return;
        }
        int last = num % 10;
        int next = last + k;
        if(next >= 0 && next <= 9){
            backtracking(n , k , len + 1 , num * 10 + next , result);
        }
        int next2 = last - k;
        if(k!= 0  && next2 >=0  && next2 <= 9){
            backtracking(n , k , len + 1 , num * 10 + next2 , result);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>result;
        for(int i = 1 ; i <= 9 ; i++){
            backtracking(n , k , 1 , i , result);
        }
        return result;
    }
};