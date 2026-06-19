class minHeap {
  private:
    // Initialize your data members
    vector<int> arr;

  public:
  
  
    void heapify(int i) {
        int smallest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<arr.size() && arr[left]<arr[smallest]) smallest=left;
        if(right<arr.size() && arr[right]<arr[smallest]) smallest=right;
        
        if(smallest!=i) {
            swap(arr[smallest],arr[i]);
            heapify(smallest);
        }
    }
  
  
  
  

    void push(int x) {
        // Insert x into the heap
        if(arr.size()==0) {
            arr.push_back(x);
            return ;
        }
        
        arr.push_back(x);
        int i = arr.size()-1;
        while(i>0) {
            int parent = (i-1)/2;
            if(arr[parent]>arr[i]) {
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else {
                break;
            }
        }
        
    }

    void pop() {
        // Remove the top (minimum) element
        if(arr.size()==0) return ;
        
        if(arr.size()==1) {
            arr.pop_back();
            return ;
        }
        
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