 int count =0;
    int MOD = 1e9 +7;
    
  
    void ans(int n,int k, int target,int dice,int i) {
        
          if(dice==n) {
                 if(i == target) count = (count+1)%MOD;

                  return;
          }

           

           for(int face=1;face<=k;face++) {
                  if(i+face>target) break;
                  ans(n,k,target,dice+1,i+face);
           }

           return ;
    } 




    int numRollsToTarget(int n, int k, int target) {
        int dice=0;
        ans(n,k,target,dice,0);
        return count;
    }