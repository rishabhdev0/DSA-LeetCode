class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int val : arr1){
            while(!st.count(val) && val > 0){
                st.insert(val);
                val /= 10;
            }
        }
        int max_len = 0;
        for(int val : arr2){
            while(!st.count(val) && val > 0){
                val/=10;
            }
            if(val > 0){
                max_len = max(max_len , static_cast<int>(log10(val) + 1));
            }
        }
        return max_len;
    }
};