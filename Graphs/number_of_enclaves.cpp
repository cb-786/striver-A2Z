void rec(vector<vector<int>>& board,int i, int j,vector<vector<int>> &vis) {
            
    vis[i][j] = 1;
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    for(int k=0;k<4;k++) {
        if(i+dx[k] >=0 && i+dx[k] <board.size() && j+dy[k] < board[0].size() && j+dy[k] >=0) {
            if(!vis[i+dx[k]][j+dy[k]] && board[i+dx[k]][j+dy[k]] == 1) {
                rec(board,i+dx[k],j+dy[k],vis);
        }
        }    
    }   
        return ;

}






int numEnclaves(vector<vector<int>>& grid) {
int n = grid.size();
int m = grid[0].size();
    vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));

    for(int i=0;i<n;i++) {
        if(!vis[i][0] && grid[i][0]==1) {
            rec(grid,i,0,vis);
        }
    }

    for(int j=0;j<m;j++) {
        if(!vis[0][j] && grid[0][j]==1) {
            rec(grid,0,j,vis);
        }
    }

    for(int i=0;i<n;i++) {
        if(!vis[i][m-1] && grid[i][m-1]==1) {
            rec(grid,i,m-1,vis);
        }
    }

   for(int j=0;j<m;j++) {
        if(!vis[n-1][j] && grid[n-1][j]==1) {
            rec(grid,n-1,j,vis);
        }
    }
    int ans=0;
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
             if(grid[i][j]==1 && !vis[i][j]) {
                ans++;
             }
        }
    }
    return ans;

}