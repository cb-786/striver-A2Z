void rec(vector<vector<char>>& board,int i, int j,vector<vector<int>> &vis) {
            
    vis[i][j] = 1;
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    for(int k=0;k<4;k++) {
        if(i+dx[k] >=0 && i+dx[k] <board.size() && j+dy[k] < board[0].size() && j+dy[k] >=0) {
            if(!vis[i+dx[k]][j+dy[k]] && board[i+dx[k]][j+dy[k]] == 'O') {
                rec(board,i+dx[k],j+dy[k],vis);
        }
        }    
    }   
        return ;

}




void solve(vector<vector<char>>& board) {
int n = board.size();
int m = board[0].size();
    vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));

    for(int i=0;i<n;i++) {
        if(!vis[i][0] && board[i][0]=='O') {
            rec(board,i,0,vis);
        }
    }

    for(int j=0;j<m;j++) {
        if(!vis[0][j] && board[0][j]=='O') {
            rec(board,0,j,vis);
        }
    }

    for(int i=0;i<n;i++) {
        if(!vis[i][m-1] && board[i][m-1]=='O') {
            rec(board,i,m-1,vis);
        }
    }

   for(int j=0;j<m;j++) {
        if(!vis[n-1][j] && board[n-1][j]=='O') {
            rec(board,n-1,j,vis);
        }
    }

    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
             if(board[i][j]=='O' && !vis[i][j]) {
                board[i][j] ='X';
             }
        }
    }

}