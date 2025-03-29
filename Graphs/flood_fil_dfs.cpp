void dfs(vector<vector<int>>& image,vector<vector<int>> &vis,int sr,int sc,int &color,int old) {

    if(image[sr][sc]==color) return ;
    image[sr][sc] = color;
    vis[sr][sc] = 1;
    int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        for(int k=0;k<4;k++) {
            int newi = sr + dx[k];
            int newj = sc + dy[k];
            if(newi<image.size() && newj<image[0].size() && newi>=0 && newj>=0 && image[newi][newj]==old && !vis[newi][newj]) {
                dfs(image,vis,newi,newj,color,image[newi][newj]);
            }
        }

}

vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int color) {
    vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
     dfs(image,vis,sr,sc,color,image[sr][sc]);
     return image;

}