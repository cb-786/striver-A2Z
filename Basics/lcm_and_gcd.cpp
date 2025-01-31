 vector<int> lcmAndGcd(int a, int b) {
        int orignal_A = a, orignal_B = b;
        
        // Compute GCD using Euclidean algorithm
        while(a > 0 && b > 0){
            if(a > b){
                a = a % b;
            }else{
                b = b % a;
            }
        }
        
        int gcd = (a == 0) ? b : a;
        
        // Now here we Compute LCM using the formula: LCM * GCD = a * b
        int lcm = (orignal_A * orignal_B) / gcd;
        
        return {lcm, gcd};
    }