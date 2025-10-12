int setBit(int n) {
        // Write Your Code here
        vector<int> binary;
        int ans = 0;
        int f =0;
        int power = 1;
        while(n>1) {
            if(n%2==0 && f==0) {
                f=1;
             ans += 1 * power;
             power*=2;
             n=n/2;
             continue ;
            }
            
            ans += (n%2) * power;
            n=n/2;
            power *=2;
        }
        if(n==1) ans+=1*power;
        
        if(f==0) {
            ans = ans * 2 + 1;
        }
        return ans;
    }