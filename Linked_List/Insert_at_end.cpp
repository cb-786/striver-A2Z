Node *insertAtEnd(Node *head, int x) {
        Node *newnode = new Node(x);
        Node *temp = head;
        
        if(head == NULL) {
            head=newnode;
            return head;
        }
        
        
        
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        temp -> next = newnode;
        return head;
        
    }