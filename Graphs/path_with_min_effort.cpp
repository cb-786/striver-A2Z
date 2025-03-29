bool issafe(int x,int y,int m,int n) {
    if(x<m && y<n && x>=0 && y>=0 ) {
       return true;
    }
    else {
       return false;
    }
}

int minimumEffortPath(vector<vector<int>>& heights) {
int m = heights.size();
int n = heights[0].size();
vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> h;
dist[0][0] = 0;
h.push({0,{0,0}});

while(!h.empty()) {
   pair<int,pair<int,int>> node = h.top();
   h.pop();
   int currdiff = node.first;
   int x = node.second.first;
   int y = node.second.second;
   

   int dx[4] = {-1,0,1,0};
   int dy[4] = {0,-1,0,1};
   for(int i=0;i<4;i++) {
       int newx = x + dx[i];
       int newy = y + dy[i];
       if(issafe(newx,newy,m,n) ) {
           int maxdiff = max(currdiff,abs(heights[x][y] - heights[newx][newy]));
           if (maxdiff < dist[newx][newy]) {  
               dist[newx][newy] = maxdiff;
               h.push({dist[newx][newy],{newx,newy}});
           }
           
       }

   }

}

return dist[m-1][n-1];

}