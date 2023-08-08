class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int delrow[] = {-1,-1,-1,0,1,1,1,0};
        int delcol[] = {-1,0,1,1,1,0,-1,-1};
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ln =0;
                for(int k=0;k<8;k++){
                    int nrow = i+delrow[k];
                    int ncol = j+delcol[k];
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && board[nrow][ncol] == 1){
                        ln++;
                    }
                }
                cout<<ln<<" " ;
                
                if(board[i][j] == 1){
                    if(ln<2){
                        ans[i][j] = 0;
                    }
                    if(ln == 2 || ln == 3){
                        ans[i][j] = 1;
                    }
                    if(ln>3){
                        ans[i][j] = 0;
                    }
                }else {
                    if(ln == 3){
                        ans[i][j] = 1;
                    }
                }
            }
            cout<<endl;
        }
        board = ans;
        
    }
};