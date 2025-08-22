int minimumArea(vector<vector<int>>& grid) {
        int hmin = INT_MAX;
        int hmax = INT_MIN;
        int wmin = INT_MAX;
        int wmax = INT_MIN;

        for(int i = 0 ; i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    hmin = min(hmin,i);
                    hmax = max(hmax,i);
                    wmin = min(wmin,j);
                    wmax = max(wmax,j);
                }
            }
        }
        
        return (hmax-hmin+1)*(wmax-wmin+1);
    }