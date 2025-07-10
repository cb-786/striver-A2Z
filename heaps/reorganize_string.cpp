string reorganizeString(string s) {
    priority_queue<pair<int,char>> pq;
    unordered_map<char,int> map;

    for(int i=0;i<s.size();i++) {
        map[s[i]]++;
    }

    for(const auto& pair:map) {
        pq.push({pair.second,pair.first});
    }

    string ans;
    while(!pq.empty()) {

        auto tmp = pq.top();
        pq.pop();
        ans.push_back(tmp.second);
        if(!pq.empty()) {
        auto nxt = pq.top();
        pq.pop();
        ans.push_back(nxt.second);
        if(nxt.first!=1) {
            pq.push({nxt.first-1,nxt.second});
        }
        }
        
        if(tmp.first!=1) {
            pq.push({tmp.first-1,tmp.second});
        }
        
    }

    for (int i = 1; i < ans.size(); i++) {
    if (ans[i] == ans[i-1]) return "";  // Invalid
}

    return ans;

}