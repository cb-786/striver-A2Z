bool isPowerOfThree(long long n) {
        if(n<=0) return 0;

        long long curr = 1;
        while(curr<n) {
            curr=curr*3;
        }
        if(curr==n) return 1;

        return 0;
    }
};