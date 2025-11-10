class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row* col - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int index = matrix[mid / col][mid % col];
            if(index == target) return true;
            else if(index < target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};