class Solution {
public:

    long long bitadd(long long a,long long b) {
        while(b!=0) {
            unsigned long long c=a&b;
            a=a^b;
            b=c<<1;
        }
        return a;
    }

    long long bitsub(long long a,long long b) {
        long long negb=bitadd(~b,1);
        return bitadd(a,negb);
    }



    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
       int quotient=0;
       bool neg = (dividend<0) ^ (divisor<0);
       long long n=dividend;
       if(dividend<0) {
        n=bitadd(~n,1);
       }
    //    long long n = dividend;
    long long d = divisor;
       if(d<0) {
        d=bitadd(~divisor,1);
       }
    //    long long d = divisor;
       for(int i=31;i>=0;i--) {
        if((n>>i)>=d) {
            quotient=bitadd(quotient,1LL<<i);
            n=bitsub(n,d<<i);
        }
       }

       if(neg) {
        return bitadd(~quotient,1);
       }
       return quotient;


    }
};