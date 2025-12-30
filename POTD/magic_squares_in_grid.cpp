bool isMagic(vector<vector<int>>& g, int i, int j) {
        if (g[i+1][j+1] != 5) return false;

        set<int> s;
        for (int x = i; x < i+3; x++)
            for (int y = j; y < j+3; y++)
                s.insert(g[x][y]);

        if (s.size() != 9) return false;
        for (int v : s)
            if (v < 1 || v > 9) return false;

        int s1 = g[i][j] + g[i][j+1] + g[i][j+2];
        int s2 = g[i+1][j] + g[i+1][j+1] + g[i+1][j+2];
        int s3 = g[i+2][j] + g[i+2][j+1] + g[i+2][j+2];
        int s4 = g[i][j] + g[i+1][j] + g[i+2][j];
        int s5 = g[i][j+1] + g[i+1][j+1] + g[i+2][j+1];
        int s6 = g[i][j+2] + g[i+1][j+2] + g[i+2][j+2];
        int s7 = g[i][j] + g[i+1][j+1] + g[i+2][j+2];
        int s8 = g[i][j+2] + g[i+1][j+1] + g[i+2][j];

        return s1 == s2 && s2 == s3 && s3 == s4 &&
               s4 == s5 && s5 == s6 && s6 == s7 && s7 == s8;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i + 2 < grid.size(); i++)
            for (int j = 0; j + 2 < grid[0].size(); j++)
                if (isMagic(grid, i, j)) ans++;
        return ans;
    }