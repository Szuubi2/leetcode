class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> out;
        vector<string> board(n, string(n, '.'));
        backtrackNQueens(out, board, 0, n);
        return out;
    }

    bool isSafe(vector<string>& board, int x, int y, int n) {
        for (int i = 0; i < n; ++i) {
            if (board[i][y] == 'Q') return false;
        }
        
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = x + 1, j = y + 1; i < n && j < n; ++i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = x + 1, j = y - 1; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }

    void backtrackNQueens(vector<vector<string>>& out, vector<string>& board, int x, int n) {

        if (x == n) {
            out.push_back(board);
            return;
        }

        for (int y = 0; y < n; ++y) {
            if (isSafe(board, x, y, n)) {
                board[x][y] = 'Q';
                
                backtrackNQueens(out, board, x + 1, n);
                
                board[x][y] = '.';
            }
        }
    }
};
