 bool isPowerOfTwo(long long n) {
        long long curr = 1;
        while(n>=curr) {
            if(n==curr) {
                return true;
            }
            curr = curr*2;
        }
        return false;
    }