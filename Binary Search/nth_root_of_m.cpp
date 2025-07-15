int NthRoot(int n, int m) {
  int s=0;
  int e = m;
  int mid = s + (e-s)/2;
  int ans = -1;
  while(s<=e) {
    
        long long pwr = 1;
        for (int i = 0; i < n; i++) {
            pwr *= mid;
            if (pwr > m) break; // avoid overflow
        }

       if(pwr == m) return mid;

       if(pwr < m) {
         int ans = mid;
         s=mid+1;
       } else {
         e= mid-1;
       }

       mid = s + (e-s)/2;
  }
  return ans;
}