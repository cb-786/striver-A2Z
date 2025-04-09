bool rec(vector<vector<int>> &graph,vector<int> &col,int curr,int i) {
    col[i]=curr;
           for(int j=0;j<graph[i].size();j++) {
                  if( col[graph[i][j]] == -1 ) {
                    for(auto k : col) {
                        cout << k << " ";
                    }
                    cout << endl;
                     
                     if(!rec(graph,col,!curr,graph[i][j])) {
                        return false;
                     }
                  }

                  else if(col[graph[i][j]] == curr) return false;
           }
           return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> col(graph.size(),-1);
    
    for(int i=0;i<graph.size();i++) {
        if(col[i]==-1) {
            col[i]=0;
            if(!rec(graph,col,0,i)) return false;
        }
    }
    return true;
}