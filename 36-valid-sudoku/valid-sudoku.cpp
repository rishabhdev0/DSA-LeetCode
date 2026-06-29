class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                string val = string(1, board[i][j]);

                string row = val + "row" + to_string(i);
                string col = val + "col" + to_string(j);
                string box = val + "box" + to_string(i / 3) + to_string(j / 3);

                if(st.find(row) != st.end() ||
                   st.find(col) != st.end() ||
                   st.find(box) != st.end()) {
                    return false;
                }

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};