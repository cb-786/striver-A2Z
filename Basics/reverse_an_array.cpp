void rev(vector<int> &arr,int i) {
       
        if(arr.size()<=0) {
            return ;
        }
        
        int temp = arr[i];
        arr.erase(arr.begin());
        rev(arr,i++);
        arr.push_back(temp);
        return ;
        
    }
  
  
    void reverseArray(vector<int> &arr) {
        rev(arr,0);
    }