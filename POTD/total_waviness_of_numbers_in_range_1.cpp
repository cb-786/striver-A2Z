int totalWaviness(int num1, int num2) {
        int l = 0;
        int m = 0;
        int r = 0;
        int ans = 0;
        for(int i = num1;i<=num2;i++) {
            int num = i;
            int exp=1;
            while(num!=0) {
                r=num%10;
                num=num/10;
                if(num==0) break;
                m=num%10;
                num=num/10;
                if(num==0) break;
                l=num%10;

                if(m>r && m>l) ans++;

                if(m<r && m<l) ans++;

                num=(i/(pow(10,exp)));
                exp++;
            } 
        }
        return ans;
    }