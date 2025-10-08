#include<bits/stdc++.h>
bool isloop(int u,int v,int n ,vector<vector<int>> &adj) {
			if(u==v) return true;

			queue<int> q;
			q.push(u);
			vector<int> vis(n+1,0);
			vis[u] = 1;

			while(!q.empty()) {
				int currnode = q.front();
				q.pop();

				if(currnode == v) return true;

				for(const auto &nbr : adj[currnode]) {
					if(!vis[nbr]) {
						q.push(nbr);
						vis[nbr] = 1;
					}
				}
			}

			return false;
}




int kruskalMST(int n, vector<vector<int>> &edges)
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	for(const auto &edge : edges ) {
		pq.push({edge[2],{edge[0],edge[1]}});
	}

	vector<vector<int>> adj(n+1);
	int added = 0;
	int ans =0;

	while(added != n-1 && !pq.empty()) {
		auto edge = pq.top();
		pq.pop();

		int u = edge.second.first;
		int v = edge.second.second;

		if(!isloop(u,v,n,adj)) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			ans+=edge.first;
			added++;
		}
	}

	return ans;
}
