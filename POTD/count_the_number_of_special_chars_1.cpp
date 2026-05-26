int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<int> vis(26,0);
        vector<int> bvis(26,0);
        vector<int> done(26,0);
        for(const auto &c : word) {
            // char c = word[i];
            // cout << c-'a'+'A' << endl;
            
            if(c-'a'>=0 && c-'a'<=26) {
                if(done[c-'a']==1) continue ;
                if(vis[c-'a']!=1)
                vis[c-'a']++;
                // cout << "dup " << c << " detected at i= " << i << endl;

                if(bvis[c-'a']==1) {
                    done[c-'a']=1;
                    ans++;
                }
                continue ;
            }
            if(c-'A'>=0 && c-'A'<=26) {
                if(done[c-'A']==1) continue;
                if(bvis[c-'A']==0)
                bvis[c-'A']++;
                // cout << "dup " << c << " detected at i= " << i << endl;
                if(vis[c-'A']==1) {
                    done[c-'A']=1;
                    ans++;}
            }
        }
        return ans;
    }