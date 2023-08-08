class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int delrow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int ln = 0;
                for(int k = 0; k < 8; k++) {
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && (board[nrow][ncol] == 1 || board[nrow][ncol] == 3)) {
                        ln++;
                    }
                }

                if(board[i][j] == 1) {
                    if(ln < 2 || ln > 3) {
                        ans[i][j] = 0;
                    }
                    else {
                        ans[i][j] = 1;
                    }
                }
                else {
                    if(ln == 3) {
                        ans[i][j] = 1;
                    }
                }
            }
        }

        // Update the original board with the values from ans
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = ans[i][j];
            }
        }
    }
};