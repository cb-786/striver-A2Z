// int rec(vector<vector<int>> &grid,int i,int j,int &fin,vector<vector<bool>> &vis) {
            
    //             if(grid[i][j] == 1) {
    //                 return INT_MAX;
    //             }

    //             if(i==grid.size()-1 && j==grid.size()-1) {
    //                   fin = min(ans,fin);
    //                   return fin;
    //             }
    //             int ans=1;
    //             int dx[8] = {1,0,-1,0,1,-1,-1,1};
    //             int dy[8] = {0,1,0,-1,1,1,-1,-1};
    //             for(int k=0;k<8;k++) {
    //                 int x = i + dx[k];
    //                 int y = j + dy[k];
    //                 if(x<grid.size() && y<grid.size() && x>=0 && y>=0 && grid[x][y]==0 && vis[i][j] ==0) {
    //                     vis[i][j] = 1;
    //                     ans = 1 + rec(grid,x,y,fin,vis);
    //                      vis[i][j] =0;
    //                 }
    //             }
                
    //             return ans; 

                
    // }










    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size()==1 && grid[0][0]==0) return 1; 
        if(grid[0][0]==1) return -1;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(grid.size(),vector<int>(grid.size(),INT_MAX));
                vector<vector<bool>> vis(grid.size(),vector<bool> (grid.size(),0));

        
                while(!pq.empty()) {
                    auto front = pq.top();
                    int distance = front.first;
                    int i = front.second.first;
                    int j = front.second.second;
                    pq.pop();
                    vis[i][j] = 1;
                int dx[8] = {1,0,-1,0,1,-1,-1,1};
                int dy[8] = {0,1,0,-1,1,1,-1,-1};
                for(int k=0;k<8;k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x<grid.size() && y<grid.size() && x>=0 && y>=0) {
                       if(grid[x][y]==0 && vis[x][y] != 1) {
                            if(distance+1 < dist[x][y]){
                                vis[x][y] = 1;
                                dist[x][y] = min(distance+1,dist[x][y]);
                                pq.push({distance+1,{x,y}});
                            }
                       }
                        

                    }
                }
            }
                
        // int fin = INT_MAX;
        // vector<vector<bool>> vis(grid.size(),vector<bool> (grid.size(),0));
        // int ans =rec(grid,0,0,fin,vis);
        // if(ans==INT_MAX) return -1;

        // return ans;
        if(dist[grid.size()-1][grid.size()-1] != INT_MAX)
        return dist[grid.size()-1][grid.size()-1]+1;

        return -1;
    }