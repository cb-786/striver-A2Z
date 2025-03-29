void bfs(vector<vector<char>>& grid,int i,int j) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});


    while(!q.empty()) {
        pair<int,int> node = q.front();
        int i = node.first;
        int j = node.second;
        
        q.pop();
        


        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        for(int k=0;k<4;k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if(newi<m && newj<n && newi>=0 && newj>=0) {
                if(grid[newi][newj]=='1') {
                    
                    grid[newi][newj]='2';
                    q.push({newi,newj});
                }
            }
        }

    }
}



int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0 ;
    
    for(int i =0;i<m;i++) {
              for(int j=0;j<n;j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '2';
                    bfs(grid,i,j);  
                }
              }
    }
    return ans;

    
}