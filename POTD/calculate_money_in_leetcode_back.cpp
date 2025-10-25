int totalMoney(int n) {
        int ini = 28;
        int ans = 0;
        if(n<7) {
            while(n!=0) {
                ans += n;
                n--;
            }
            return ans;
        }

        int rem = n%7;
        int tot = n/7;
        int i = 1;
        while(rem!=0) {
            ans+=i+tot;
            i++;
            rem--;
        }
        while(tot!=0) {
            ans+=ini;
            ini +=7;
            tot--;
        }
        return ans;

    }