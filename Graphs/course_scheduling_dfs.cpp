void dfs(vector<vector<int>>& graph,int& count, vector<int>& in, int node){
    count++;
    in[node]=-1;
    for(auto neighbours : graph[node]){
        in[neighbours]--;
        if(in[neighbours] == 0){
            dfs(graph, count, in, neighbours);
        }
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> in(numCourses,0);
    int count=0;

    for(int i=0;i<prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back( prerequisites[i][0] );
        in[prerequisites[i][0]]++;
    }

    for(int i=0;i<numCourses; i++){
        if(in[i] == 0){
            dfs(graph, count, in, i);
        }
    }
    return count == numCourses;

}