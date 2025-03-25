vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,list<int>> adj;
vector<int> vis(numCourses,0);
vector<int> toposort;
for(auto row : prerequisites) {
   adj[row[0]].push_back(row[1]);
}

vector<int> indeg(numCourses, 0);  

for(auto &pair : adj) {
   for(auto nbr : pair.second) {
       indeg[nbr]++;
   }
}



queue<int> q;
for(int i=0;i<indeg.size();i++) {
   if(indeg[i]==0) {
      q.push(i);
   }
}


while(!q.empty()) {
   int frontnode = q.front();
   vis[frontnode] = 1;
   toposort.push_back(frontnode);
   q.pop();                                                
        
   for(auto nbr:adj[frontnode]) {
      if(!vis[nbr]) {
       indeg[nbr]--;
       if(indeg[nbr]==0) {
           q.push(nbr);
       }
      }
   }

 
}

if(toposort.size() == numCourses) {
    reverse(toposort.begin(),toposort.end());
    return toposort;
}

return {};



}