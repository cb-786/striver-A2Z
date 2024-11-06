 int select(int arr[], int i)
    {
      
        for(int k=0;k<i;k++) {
            if(arr[k]>arr[i]) {
                swap(arr[k],arr[i]);
            }
        }
    }
     
    void selectionSort(int arr[], int n)
    {
       for(int i=0;i<n;i++) {
           select(arr,i);
       }
    }