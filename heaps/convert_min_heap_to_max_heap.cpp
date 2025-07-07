void heapify(vector<int> &arr,int ind) {
    int largest = ind;
    
    int l = 2*ind+1;
    int r = 2*ind+2;
    
      if(l < arr.size() && arr[largest] < arr[l]) {
         largest = l;
     }
     if(r < arr.size() && arr[largest] < arr[r]) {
         largest = r;
     }
    
    if(largest!=ind) {
        swap(arr[largest],arr[ind]);
        heapify(arr,largest);
    }
}



 void convertMinToMaxHeap(vector<int> &arr, int N) {
     for(int i=(N/2)-1;i>=0;i--) {
         heapify(arr,i);
     }
 }