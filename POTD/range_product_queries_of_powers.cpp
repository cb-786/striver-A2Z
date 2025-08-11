 vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        
        int curr = 1;
        
        while(n != 0) {
            while(curr <= n) {
                curr *= 2;
            }
            curr = curr / 2;
            
            powers.push_back(curr);
            
            n -= curr;
            curr = 1;
        }
        
        reverse(powers.begin(),powers.end());
        vector<int> ans;
        const int MOD = 1000000007;
        
        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            
            long long product = 1;
            for(int j = l; j <= r; j++) {
                product = (product * powers[j]) % MOD;
            }
            ans.push_back(product);
        }

        return ans;
    }