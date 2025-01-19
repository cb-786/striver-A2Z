double powHelper(double x, long long n) {
        // Base case
        if (n == 0) return 1.0;

        // Recursive case: divide the problem
        double half = powHelper(x, n / 2);

        if (n % 2 == 0) {
            return half * half; // If `n` is even
        } else {
            return x * half * half; // If `n` is odd
        }
    }

    double myPow(double x, int n) {
        long long n1 = n; // Convert `n` to long long to handle overflow
        if (n1 < 0) {
            x = 1 / x;    // For negative powers, take reciprocal of `x`
            n1 = -n1;     // Work with the positive equivalent of `n`
        }
        return powHelper(x, n1);
    }