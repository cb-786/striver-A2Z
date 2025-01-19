long long int MOD = 1e9 +7;
    long long int powHelper(int x, long long n) {
        // Base case
        if (n == 0) return 1;

        // Recursive case: divide the problem
        long long int half = powHelper(x, n / 2);

        if (n % 2 == 0) {
            return (half * half)%MOD; // If `n` is even
        } else {
            return (x * half * half)%MOD; // If `n` is odd
        }
    }
    
 
    int countGoodNumbers(long long n) {
        if(n==1) {
            return 5;
        }
        
        long  long int half = n/2;
        if(n%2==1) return (powHelper(5,half) * powHelper(4,half) * 5)%MOD;

        return (powHelper(5,half) * powHelper(4,half))%MOD;

    }