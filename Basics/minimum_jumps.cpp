int minJumps(vector<int>& arr) {
        int maxind=0;
        int count=0;
       int currend = 0;
    
       if(arr.size() == 1) {
        return 0;
       }
       
        for(int i=0;i<=maxind;i++) {
          
           maxind = max(maxind,i+arr[i]);
            
            if(currend == i) {
                count++;
                currend = maxind;

                if(maxind>=arr.size()-1) return count;
                
            }
             
            
        }
        return -1;
    }