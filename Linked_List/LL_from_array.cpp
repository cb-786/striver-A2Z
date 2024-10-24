 Node* constructLL(vector<int>& arr) {
       
     
       Node *head = new Node(arr[0]);
       Node *tail = head;
       for(int i=1;i<arr.size();i++) {
           
            Node *newnode = new Node(arr[i]);
            
              tail->next = newnode;
              tail = newnode;
       }
       
       
       
       
       return head;
       
       
       
       
       
    }