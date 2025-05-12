bool chk(vector<int>& digits,int p) {
    vector<bool> used(digits.size(),0);
    while(p!=0) {
        int t = p%10;
        p=p/10;
        int flag=0;
        for(int i=0;i<digits.size();i++) {
            
            if(digits[i]==t && !used[i]) {
                    used[i] = 1;
                    flag=1;
                    break;
            }
        }
        if(flag==0) return false;
    }
    return true;
}


vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> ans;
    vector<int> poss;
    for(int i=100;i<=999;i++) {
        if(i%2==0) {
            poss.push_back(i);
        }
    }

    for(auto k : poss) {
         if(chk(digits,k)) {
            ans.push_back(k);
         }
    }

    return ans;
}