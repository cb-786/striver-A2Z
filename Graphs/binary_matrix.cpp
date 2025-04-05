vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));

        

     queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));

    for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                    if(mat[i][j]==0) {
                        q.push({{i,j},0});
                        vis[i][j] =1;
                    }
            }
        }
     

    while(!q.empty()) {
        auto front=q.front();
        q.pop();
        int i=front.first.first;
        int j = front.first.second;
        int dist = front.second;
        

            
            
            ans[i][j] = dist;
             
                int dx[4] = {-1,0,1,0};
                int dy[4] = {0,1,0,-1};
                
                for(int k=0;k<4;k++) {
                    if(i+dx[k] >=0 && i+dx[k]<mat.size() && j+dy[k]>=0 && j+dy[k]<mat[0].size() && !vis[i+dx[k]][j+dy[k]]) {        vis[i+dx[k]][j+dy[k]]=1;
                        if(mat[i+dx[k]][j+dy[k]]==1) {
                            q.push({{i+dx[k],j+dy[k]},dist+1});
                        }


                              
                    }

                }
                
             
    }
    return ans;
}