void topSortBfs(int n, string& topoOrder,unordered_map<char,list<char>> &adj) {
    queue<char> q;
    map<char,int> indegree;
    
    //initialise kardi indegree ssanki
    for( auto i : adj) {
        for(auto nbr: i.second) {
            indegree[nbr]++;
        }
    }
    //push all zero indegree wali node into queue
    for(char node='a'; node<n+'a'; node++) {
        if(indegree[node] == 0) {
            q.push(node);
        }
    }

    //BFS chalate hai
    while(!q.empty()) {
        char frontNode = q.front();
        q.pop();
        topoOrder.push_back(frontNode);

        for(auto nbr: adj[frontNode]) {
            indegree[nbr]--;

            //check for zero
            if(indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
}

string getAlienLanguage(vector<string> &dictionary, int k)
{
unordered_map<char,list<char>> adj;
string ans;
for(int i=0;i<dictionary.size()-1;i++) {
       string s1 = dictionary[i];
       string s2 = dictionary[i+1];
        int j=0;
       while(j<s1.size() && j<s2.size()) {
             if(s1[j]!=s2[j]) {
                 int flag=0;
                 for(auto ele : adj[s1[j]]) {
                     if(ele == s2[j]) {
                         flag=1;
                         break;
                     }
                 }
                 if(flag==0)
                 adj[s1[j]].push_back(s2[j]);
                 break;
             }
             j++;
       }
}

topSortBfs(k,ans,adj);
return ans;


}