class MyStack {
    public:
        queue<int> q1;
        queue<int> q2;
        int size=100;
        int toggle=0;
        MyStack() {
            
        }
        
        void push(int x) {
            if(toggle==0) {
                q1.push(x);
                while(!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
                toggle=1;
            }
    
            else if (toggle==1) {
                q2.push(x);
                while(!q1.empty()) {
                    q2.push(q1.front());
                    q1.pop();
                }
                toggle=0;
            }
        }
        
        int pop() {
            if(empty()) return -1;
    
    
            if(toggle==0) {
                int tmp = q2.front();
                q2.pop();
                return tmp;
            }
    
            else if(toggle==1) {
                int tmp = q1.front();
                q1.pop();
                return tmp;
            }
            return -1;
        }
        
        int top() {
    
            if(empty()) return -1;
    
            if(toggle==0) {
                return q2.front();
            }
            else if(toggle==1) return q1.front();
    
           return -1;
        }
        
        bool empty() {
            if(q1.empty() && q2.empty()) return true;
    
            return false;
        }
    };