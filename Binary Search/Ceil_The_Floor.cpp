void removeduplicates(vector<int> &arr) {
      vector<int> k;
      
      for(int i=0;i<arr.size()-1;i++) {
          if(arr[i]==arr[i+1]) {
              k.push_back(i+1);
          }
      }
     
      while(!k.empty()) {
         int  n = k.size();
          arr.erase(arr.begin()+k[n-1]);
          k.pop_back();
          
      }
      
  }
  
  
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        vector<int> ans;
       sort(arr.begin(),arr.end());
       removeduplicates(arr);
       int n=arr.size();
       
       if(x>arr[n-1]) {
           
           ans.push_back(arr[n-1]);
           ans.push_back(-1);
           return ans;
           
       }
       
       if(x<arr[0]) {
           
           ans.push_back(-1);
           ans.push_back(arr[0]);
           return ans;
           
       }
       
       for(int i=0;i<arr.size();i++) {
           
           if(arr[i]==x) {
               ans.push_back(arr[i]);
               ans.push_back(arr[i]);
               return ans;
           }
           
           if(arr[i]<x && x<arr[i+1]) {
               
               ans.push_back(arr[i]);
               ans.push_back(arr[i+1]);
               
           }
       }
       
       if(ans.size()==0) {
           
           ans.push_back(-1);
           
       }
       return ans;
    }