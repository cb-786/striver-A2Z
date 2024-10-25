Node* constructDLL(vector<int>& arr) {
     Node *head = new Node(arr[0]);
     Node* temp = head;
     for(int i=1;i<arr.size();i++) {
         Node *newnode = new Node(arr[i]);
         temp->next = newnode;
         newnode->prev = temp;
         temp = newnode;
     }
     
     return head;
    }