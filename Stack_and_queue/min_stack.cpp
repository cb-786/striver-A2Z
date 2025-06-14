class MinStack {
    public:
        pair<int,int> *arr;
        int topo;
        MinStack() {
            arr= new pair<int,int>[30000];
            topo=-1;
        }
        
        void push(int val) {
    
            if(topo==-1) {
                topo++;
                arr[topo] = {val,val};
            }
    
    
            else if(topo!=30000-1) {
                auto curr = arr[topo];
                int mini = curr.second;
                int ele = curr.first;
                
                if(val<mini) {
                    topo++;
                    arr[topo] = {val,val};
                }
    
                else {
                    topo++;
                    arr[topo] = {val,mini};
                }
            }
        }
        
        void pop() {
            if(topo!=-1) {
              topo--;
            }
        }
        
        int top() {
            if(topo!=-1 && topo!=30000) {
                return arr[topo].first;
            }
            return -1;
        }
        
        int getMin() {
           return (topo==-1) ? -1 : arr[topo].second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */