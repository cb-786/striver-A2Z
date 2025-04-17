void floydWarshall(vector<vector<int>> &dist) {
    for(int helper = 0;helper<dist.size();helper++) {
       for(int i=0;i<dist.size();i++) {
           for(int j=0;j<dist[0].size();j++) {
              
                  if (dist[i][helper] !=  pow(10,8) && dist[helper][j] !=  pow(10,8)) {
                        dist[i][j] = min(dist[i][j], dist[i][helper] + dist[helper][j]);
                    }
             }
           }
       }
    }