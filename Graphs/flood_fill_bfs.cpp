vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int color) {
    int m = image.size();
    int n = image[0].size();
    queue<pair<int,int>> q;
    q.push({sr,sc});
    while(!q.empty()) {
        pair<int,int> node = q.front();
        int i = node.first;
        int j = node.second;
        q.pop();

        if(image[i][j]==color) {
            continue;
        }

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        for(int k=0;k<4;k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if(newi<m && newj<n && newi>=0 && newj>=0) {
                if(image[newi][newj]==image[i][j]) {
                    q.push({newi,newj});
                }
            }
        }
        image[i][j]=color;
    }
    return image;
}