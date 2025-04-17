void order(vector<vector<int>> &adj,stack<int> &st,int node,vector<int> &vis) {
    vis[node] = 1;
    for(auto nbr : adj[node]) {
        if(!vis[nbr]) {
            order(adj,st,nbr,vis);
        }
    }
    st.push(node);
}

void dfs(unordered_map<int,list<int>> &radj,vector<int> &rvis,int node) {
rvis[node] = 1;
for(auto nbr : radj[node]) {
if(!rvis[nbr]) {
    dfs(radj,rvis,nbr);
}
}
} 



int kosaraju(vector<vector<int>> &adj) {
int n = adj.size();
stack<int> st;
vector<int> vis(n,0);
for(int i=0;i<n;i++) {
if(!vis[i]) {
    order(adj,st,i,vis);
}
}


unordered_map<int,list<int>> radj;
for(int i=0;i<adj.size();i++) {
for(int j=0;j<adj[i].size();j++) {
    radj[adj[i][j]].push_back(i);
}
}

vector<int> rvis(n,0);
int cnt=0;
while(!st.empty()) {
int top = st.top();
st.pop();
if(rvis[top]==1) {
    continue;
}

else {
    cnt++;
    dfs(radj,rvis,top);
}


}

return cnt;
}