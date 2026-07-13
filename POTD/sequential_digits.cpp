vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int s=1;
        int sl=low;
        int sh=high;
        int d=0;
        int ddh=0;
        while(sl!=0) {
            sl=sl/10;
            d++;
        }
        while(sh!=0) {
            sh=sh/10;
            ddh++;
        }
        while(d<=ddh) {
            int s=1;
            while(s<=10-d) {
            int dd= d;
            int cd=0;
            int cs=s;
                while(dd!=0 && cs<=9) {
                    cd*=10;
                    cd+=cs;
                    dd--;
                    cs++;
                }
            if(cd>=low && cd<=high)
            ans.push_back(cd);
            else if(cd>high) return ans;
            s++;
        }
        d++;
    }
        return ans;

    }