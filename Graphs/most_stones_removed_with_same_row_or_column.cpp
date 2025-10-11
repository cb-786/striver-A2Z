class disjointset {
    public :
    vector<int> rank;
    vector<int> par;
    disjointset(int n) {
        rank.resize(n,0);
        par.resize(n);
        for(int i = 0;i<n;i++) {
            par[i] = i;
        }
    }

    int find(int k) {
        if(par[k]==k) return k;
       return par[k] = find(par[k]);
    }

    void join(int u,int v) {
        int ulpu = find(u);
        int ulpv = find(v);

        if(ulpu == ulpv ) return ;

        if(rank[ulpu] > rank[ulpv]) {
            par[ulpv] = ulpu;
        }
        else if(rank[ulpu] < rank[ulpv]) {
            par[ulpu] = ulpv;
        }
        else {
            par[ulpu] = ulpv;
            rank[ulpv]++;
        }
    }

    
 };

int removeStones(vector<vector<int>>& stones) {
     int maxrow = 0;
     int maxcol = 0;
     for(const auto &ele :stones) {
        maxrow = max(maxrow,ele[0]);
        maxcol = max(maxcol,ele[1]);
     }
     
     disjointset ds(maxrow + maxcol + 2);

     for(const auto& ele : stones) {
        ds.join(ele[0], ele[1] + maxrow + 1);
     }

    set<int> components;
     for(const auto& stone : stones) {
         components.insert(ds.find(stone[0]));
     }
     return stones.size() - components.size();
}