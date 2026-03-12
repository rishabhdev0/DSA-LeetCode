class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int j = arr.size() - 1;
        while(j - i  >= k){
           if(abs(arr[i] - x) > abs(arr[j] - x)) i++;
           else j--;    
        }
        return vector<int>(arr.begin() + i  , arr.begin() +  j + 1);
    }
};