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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)   {
        unordered_map<string,int> map;
        disjointset ds(accounts.size());
        for(int j = 0;j<accounts.size();j++) {
           const auto& acc = accounts[j];
            for(int i = 1 ;i< acc.size();i++) {
                auto it = map.find(acc[i]);
                    if(it!=map.end()) {
                            ds.join(j,it->second);
                    }

                    else {
                        map[acc[i]] = j;
                    }
            }
        }

        vector<vector<string>> ans(accounts.size());
        for(const auto& ma : map) {
            int ulp = ds.find(ma.second);


            if(ans[ulp].empty())
            ans[ulp].push_back(accounts[ulp][0]);

            ans[ulp].push_back(ma.first);
        }
        for(int i = 0;i<ans.size();i++) {
            if(ans[i].empty()) {
                ans.erase(ans.begin()+i);
                i=i-1;
                continue;
            }

            sort(ans[i].begin()+1,ans[i].end());

        }
        return ans;
    }