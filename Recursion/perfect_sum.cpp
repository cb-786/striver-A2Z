 void sumofsubset(vector<int>& arr, int &target,int sum,int &count,int i) {
       if(i==arr.size()) {
           if(sum==target) {
           count++;
           
       }
       return ;
       }
       
       sumofsubset(arr,target,sum,count,i+1);
       sumofsubset(arr,target,sum+arr[i],count,i+1);
       
       return ;
       
   }
  
  
  
  
  
    int perfectSum(vector<int>& arr, int target) {
        int count =0;
        sumofsubset(arr,target,0,count,0);
        return count;
    }