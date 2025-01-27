 vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,vector<int> &profit) {
       int count = 0;
       int tprofit = 0;
       vector<pair<int,int>> ans;
       for(int i=0;i<profit.size();i++) {
           ans.push_back({profit[i],deadline[i]});
       }
       
       sort(ans.rbegin(),ans.rend());
       
       vector<int> sequence(profit.size()+1,-1);
       
       for(int i=0;i<ans.size();i++) {
           int pro = ans[i].first;
           int dead = ans[i].second;
           
           for (int j = dead; j >= 1; j--) {
            if (sequence[j] == -1) { 
                sequence[j] = pro;
                tprofit += pro;  
                count++;  
                break;
            }
        }
       }
       
       return {count,tprofit};
       
    }