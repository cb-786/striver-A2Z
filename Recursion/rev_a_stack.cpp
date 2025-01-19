
    void rev(stack<int> &St,queue<int> &q) {
        
         if(St.empty() ) {
             
             return ;
         }
        
        
        q.push(St.top());
        St.pop();
        rev(St,q);
        St.push(q.front());
        q.pop();
       
        
        return ;
    }



    void Reverse(stack<int> &St){
        queue<int> q;
       rev(St,q);
       return ;
    }