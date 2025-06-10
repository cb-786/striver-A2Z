vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size()*grid.size();
    int actual = (n*(n+1))/2;
    vector<int> map(n+1,0);
    int bog = 0;
    int repeated=-1;
    for(const auto &row : grid) {
        for(const auto &ele : row) {
            if(map[ele]==1) {
                repeated = ele;
            }

            bog+=ele;
            map[ele] = 1;
        }
    }
    return {repeated,(actual-(bog-repeated))};
}