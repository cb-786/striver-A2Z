string FirstNonRepeating(string &s) {
    queue<char> q;
    unordered_map<char,int> map;
    string ans;
    q.push(s[0]);
    ans.push_back(s[0]);
    map[s[0]]++;
    for(int i=1;i<s.size();i++) {
        map[s[i]]++;
        q.push(s[i]);
        while(!q.empty() && map[q.front()]!=1) {
            q.pop();
        }
        if(q.empty()) {
            ans.push_back('#');
        }
        else {
            ans.push_back(q.front());
        }
}
return ans;
    
}