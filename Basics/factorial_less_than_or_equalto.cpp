
  long long fact(long long n) {
      if(n==0) return 1;
      
      if(n==1) return 1;
      
      
      
      return n*fact(n-1);
  }
  
  
  
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
       for(long long i=1;i<=n;i++) {
           if(fact(i)>n) break;
           
           ans.push_back(fact(i));
       }
       
       return ans;
    }