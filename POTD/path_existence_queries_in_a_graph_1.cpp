class DSU {
    vector<int> rank;
    vector<int> par;
    public:

    DSU(int n) {
        rank.resize(n);
        par.resize(n);
        for(int i=0;i<n;i++) {
            par[i]=i;
            rank[i]=0;
        }
    }

    int findpar(int n) {
        if(par[n]==n) return n;
        return par[n]=findpar(par[n]);
    }

    void join(int u,int v) {
        int uu=findpar(u);
        int vv = findpar(v);
        if(uu==vv) return ;

        if(rank[uu]<rank[vv]) {
            par[uu]=vv;
            // rank[vv]+=rank[uu];
        }
        else if(rank[uu]>rank[vv]) {
            par[vv]=uu;
            // rank[uu]+=rank[vv];
        }
        else {
            par[uu]=vv;
            rank[vv]+=1;
        }
    }
};



class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU mm(n);
        vector<bool> ans(queries.size(),0);
        int i=0;
        int j=1;
        for (int i = 0; i + 1 < n; i++) {
            if (abs(nums[i] - nums[i+1]) <= maxDiff) {
                mm.join(i, i+1);
            }
        }
        for(int i=0;i<n;i++) {
            mm.findpar(i);
        }
        for(int i=0;i<queries.size();i++) {
            if(mm.findpar(queries[i][0])==mm.findpar(queries[i][1])) {
                ans[i]=1;
            }
        }
        return ans;
    }
};