int findFloor(vector<long long> &v, long long n, long long x) {

       long long s = 0;
       long long e = n-1;
       long long mid = s + (e-s)/2;
       
       if(x>v[n-1]) {
           return n-1;
       }
       
      if(n==1 && v[0]<=x) {
          return 0;
      }
       
       while(s <= e) {
           
           mid = s + (e-s)/2;
           
           
           if(v[mid]==x) {
                 
                   return mid;
                  
           }
           
           
           if( x > v[mid] && v[mid+1] > x ) {
               return mid;
           }
           
           
           if(v[mid]>x && v[mid-1] <x) {
               return mid-1;
           }
           
           if(v[mid]>x) {
              
              e=mid-1;
              
           }
           
           
           if( v[mid] < x ) {
               
               s=mid+1;
               
           }
       }
       
       return -1;
       
      
    }