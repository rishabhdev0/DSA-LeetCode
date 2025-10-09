class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) return false;
        }
        
        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }
        
        int start_row = (row / 3) * 3;  //  (0, 3, or 6)
        int end_row = start_row + 2;    
        
        int start_col = (col / 3) * 3;  //  (0, 3, or 6)
        int end_col = start_col + 2;   
        
        // Check all cells in the 3x3 box
        for (int i = start_row; i <= end_row; i++) {
            for (int j = start_col; j <= end_col; j++) {
                if (board[i][j] == num) return false;
            }
        }
        
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, i, j, d)) {
                            board[i][j] = d;  
    
                            //recursion
                            if (solveSudoku(board)) {
                                return true;
                            }
                            
                            // Backtrack 
                            board[i][j] = '.';
                        }
                    }
                    return false;  // No valid number found for this cell
                }
            }
        }
        return true;  // sudoko solved
    }
};