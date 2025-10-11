class Solution {
private:
    // Manual implementation of upper_bound
    int upper_bound(vector<int>& arr, int value) {
        int left = 0;
        int right = arr.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] <= value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left; // Returns count of elements <= value
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i], mid);
            }
            
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};