 int minPartitions(string n) {
        int ans = INT_MIN;
        while(!n.empty()) {
            ans = max(n.back()-'0',ans);
            n.pop_back();
        }
        return ans;
    }