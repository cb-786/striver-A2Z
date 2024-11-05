void bubbleSort(int arr[], int n)
    {
               for(int i=0;i<n;i++) {
                   for(int j=0;j<n-i;j++) {
                       if(i==0 && j==n-1 && arr[j]>arr[j+1]) {
                           break;
                       }
                       if(arr[j]>arr[j+1]) {
                           swap(arr[j],arr[j+1]);
                       }
                   }
               }
    }