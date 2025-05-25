class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>result;
        int row_start=0,row_end=n-1;
        int col_start=0,col_end=m-1;
        while(row_start<=row_end && col_start<=col_end){
        for(int j=col_start;j<=col_end;j++){
            result.push_back(matrix[row_start][j]); // row fix , column changes
        }
        row_start++; // row ko aage badhao

        for(int i = row_start;i<=row_end;i++){
            result.push_back(matrix[i][col_end]); // column fix , row changes
        }
        col_end--; // column ko piche 

        if(row_start<=row_end){
            for(int j = col_end;j>=col_start;j--){
                result.push_back(matrix[row_end][j]); // row fix , cloun changes
            }
            row_end--; // row ko piche lao
        }
        if(col_start<=col_end){
            for(int i = row_end;i>=row_start;i--){
                result.push_back(matrix[i][col_start]); //column fix , row changes
            }
            col_start++; //colum ko aage le jao
        }
        
        }
      return result;
    }
};