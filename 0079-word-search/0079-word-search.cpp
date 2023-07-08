class Solution {
private: 
    bool dfs(vector<vector<bool>> &visited, vector<vector<char>> &board, int row , 
             int col, string word, int index){
        int n = board.size();
        int m = board[0].size();
        if(index == word.size()-1){
            cout<<"done here";
            return true;          
        }
        
        
        if(board[row][col] == word[index]){
            // cout<<word[index]<<"->";    
            visited[row][col] = true;
            index++;
            // cout<<word[index]<<"->";
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,-1,0,1};
            
            for(int i=0;i<4;i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                
                if(nrow >=0 && nrow <n && ncol >=0 && ncol<m && 
                   visited[nrow][ncol] == false && board[nrow][ncol] == word[index]){
                    if (dfs(visited, board, nrow, ncol, word, index)) {
                        return true;  // Propagate the true value
                    }
                }
            }
            visited[row][col] = false;
        }        
        return false;
    }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m= board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        for(int i=0;i<n;i++){
            for(int j =0 ; j<m;j++){
                if(board[i][j] == word[0] && dfs(visited, board, i , j , word, 0)){
                    // cout<<"Exited here";
                    return true;
                }
            }
        }
        return false;
    }
};