class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int s = 0;
        int e = row * column - 1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int index = matrix[mid / column][mid % column]; 
            if (index == target) {
                return true;
            } 
            else if (index < target) {
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }
        return false;
    }
};
