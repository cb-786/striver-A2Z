bool cyclic(vector<vector<int>>& adj, unordered_map<int, bool>& vis, unordered_map<int, int>& parent, int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    parent[src] = -1;  // Mark the source node parent as -1

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();

        for (auto nbr : adj[frontnode]) {
            if(nbr == parent[frontnode]) {
                continue;
            }
            if (!vis[nbr]) {
                q.push(nbr);
                vis[nbr] = true;
                parent[nbr] = frontnode;  
            }
            else  {  
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;

    for (int i = 0; i < adj.size(); i++) {
        if (!vis[i]) {  
            if (cyclic(adj, vis, parent, i)) {
                return true;
            }
        }
    }
    return false;
}