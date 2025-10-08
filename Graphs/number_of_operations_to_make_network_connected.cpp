class disjointset {
        public:
        vector<int> ranks;
        vector<int> par;
        int ans;
        disjointset(int n) {
            ranks.resize(n,0);
            ans=0;
            par.resize(n);
            for(int i =0;i<n;i++) par[i] = i;
        }

        int find(int u) {
            if(par[u] == u) return u;

            return par[u] = find(par[u]);
        }

        void addedge(int u ,int v) {
            int ulpu = find(u);
            int ulpv = find(v);

            if(ulpu == ulpv) {
                ans ++;
                return ;
            }

            if(ranks[ulpu] == ranks[ulpv]) {
                par[ulpu] = ulpv;
                ranks[ulpv]++;
            }

            else if(ranks[ulpu] < ranks[ulpv]) {
                par[ulpu] = ulpv;
            }

            else {
                par[ulpv] = ulpu;
            }
        }

        void pathcompression(int n) {
            for(int i =0;i<n;i++) {
                find(i);
            }
        }

        int numofcomponents(int n) {
            vector<int> vis(n,0);
            int num = 0;
            for(const auto &ele : par) {
                if(vis[ele] == 0) {
                    num++;
                    vis[ele] = 1;
                }
            }
            return num;
        }
    };


    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {
            return -1;
        }


        disjointset set1(n);
        for(const auto&ele : connections) {
            set1.addedge(ele[0],ele[1]);
        }
        set1.pathcompression(n);
        return set1.numofcomponents(n) - 1;
    }