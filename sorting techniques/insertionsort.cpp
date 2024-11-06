 int insert(int arr[], int i)
    {
      
        for(int k=0;k<i;k++) {
            if(arr[k]>arr[i]) {
                swap(arr[k],arr[i]);
            }
        }
    }
     
    void insertionSort(int arr[], int n)
    {
       for(int i=0;i<n;i++) {
           insert(arr,i);
       }
    }
