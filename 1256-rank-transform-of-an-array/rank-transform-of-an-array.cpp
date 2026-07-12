class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size(); 
        vector<int>temp = arr;
        sort(temp.begin() , temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        vector<int>result(n);
        for(int i = 0 ; i < n ; i++){
            int num = arr[i];
            auto rank = lower_bound(temp.begin() , temp.end() , num) - temp.begin() + 1;
            result[i] = rank;
        }
        return result;
    }
};