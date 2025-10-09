class Solution {
private:
    bool validateSubBox(vector<vector<char>>& board, int startRow, int startCol) {
        unordered_set<char> st;
        int endRow = startRow + 2; 
        int endCol = startCol + 2;  
        
        // Traverse from startRow to endRow and startCol to endCol
        for(int i = startRow; i <= endRow; i++) {
            for(int j = startCol; j <= endCol; j++) {
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate rows
        for(int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        
        // Validate columns
        for(int j = 0; j < 9; j++) {
            unordered_set<char> st;
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        
        // Validate 3x3 sub-boxes traversal pattern
        for(int startRow = 0; startRow < 9; startRow += 3) {
            for(int startCol = 0; startCol < 9; startCol += 3) {
                if(!validateSubBox(board, startRow, startCol)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
