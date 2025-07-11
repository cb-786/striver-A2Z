int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> map;
    for(const auto& c: tasks) {
        map[c]++;
    }
    int ans=0;
    vector<pair<int,char>> store;
    priority_queue<pair<int,char>> pq;
    for(const auto& [lock,key] : map) {
        pq.push({key,lock});
    }
    int tmp = n;
    while(!pq.empty() || !store.empty()) {
        auto top = pq.top();
                pq.pop();
                top.first--;
                if(top.first != 0)
                store.push_back(top);
                ans++;
                if(store.empty() && pq.empty()) break;
         while(tmp !=0) {
            if(!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                top.first--;
                if(top.first != 0)
                store.push_back(top);
                ans++;
                if(store.empty() && pq.empty()) break;
                
                tmp--;
                continue;
            }
            ans++;
            tmp--;
         }
         while(!store.empty()) {
            pq.push(store.back());
            store.pop_back();
         }
         tmp=n;
    }
  return ans;
}