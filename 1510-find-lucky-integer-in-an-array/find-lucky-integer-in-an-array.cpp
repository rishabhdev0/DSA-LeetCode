class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 1;
        int ans = -1;
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == arr[i - 1]) {
                count++;
            } else {
                if(count == arr[i - 1]) {
                    ans = arr[i - 1];
                }
                count = 1; 
            }
        }
        // if else condition never hit like [3,3,3,3] 
        if(count == arr.back()) {
            ans = arr.back(); // last element of the vector
        }

        return ans;
    }
};
