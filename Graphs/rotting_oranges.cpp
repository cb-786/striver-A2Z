int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int time=0;
    int ror = 0;
    int num = 0;
    queue<pair<int,int>> q;
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(grid[i][j] == 2) {
                ror++;
                num++;
                q.push({i,j});
            }
            else if(grid[i][j] ==1) {
                num++;
                
            }
        }
    }
    
    q.push({-1,-1});
    while(!q.empty()) {
         pair<int,int> node = q.front();
         q.pop();
         int i = node.first;
         int j = node.second;
         
         if(i==-1 && j==-1) {
            if(q.empty()) {
                if(ror==num) 
                return time;

                else {
                    return -1;
                }
            }
            else {
                time++;
                q.push({-1,-1});
                continue;
            }
         }
        

         int dx[4] = {-1,0,1,0};
         int dy[4] = {0,1,0,-1};
         for(int k = 0 ;k<4;k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if(newi<m && newj<n && newi>=0 && newj>=0) {
                   if(grid[newi][newj] == 1) {
                    grid[newi][newj] = 2;
                        ror++;
                        q.push({newi,newj});
                   }
            }
         }
    }


         return -1;
      

}