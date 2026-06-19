class maxHeap {
  private:
    // Initialize your data members
    vector<int> arr;
    

  public:
  
    void heapify(int i) {
        int largest =i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<arr.size() && arr[left]>arr[largest]) largest=left;
        
        if(right<arr.size() && arr[right]>arr[largest]) largest=right;
        
        if(largest!=i) {
            swap(arr[largest],arr[i]);
            heapify(largest);
        }
    }
  
    void push(int x) {
        // Insert x into the heap
        if(arr.empty()) {arr.push_back(x);
        return ;}
        arr.push_back(x);
        int i = arr.size()-1;
        while(i>0) {
            int parent = (i-1)/2;
            if(arr[parent]<arr[i]) {
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else {
                break;
            }
        }
        return ;
    }

    void pop() {
        // Remove the top (maximum) element
        if(arr.size()==1) {arr.pop_back();
        return ;}
        
        if(arr.size()==0) return;
        
        swap(arr[0],arr[arr.size()-1]);
        arr.pop_back();
        heapify(0);
        return ;
    }

    int peek() {
        // Return the top element or -1 if empty
        if(arr.size()==0) return -1;
        
        return arr[0];
    }

    int size() {
        // Return the number of elements in the heap
        return arr.size();
    }
};