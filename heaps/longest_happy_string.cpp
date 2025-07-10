string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int,char>> pq;
if (a > 0) pq.push({a,'a'});
if (b > 0) pq.push({b,'b'});
if (c > 0) pq.push({c,'c'});

string ans;
while(!pq.empty()) {
    auto top = pq.top();
    pq.pop();

    if (!ans.empty() && top.second == ans.back()) {
        if (pq.empty()) break;

        auto next = pq.top();
        pq.pop();
        ans.push_back(next.second);
        next.first--;

        if (next.first > 0)
            pq.push(next);

        pq.push(top);  // Push back the original char for later
        continue; // ⬅️ Important fix: restart loop with updated queue
    }

    int use = min(2, top.first); // Use 2 if allowed
    for (int i = 0; i < use; ++i)
        ans.push_back(top.second);

    top.first -= use;
    if (top.first > 0)
        pq.push(top);
}
return ans;
}