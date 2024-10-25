 Node* deleteNode(Node* head, int x) {
       Node* temp = head;
       
       
       while(x!=1) {
           temp = temp->next;
           x--;
       }
       
       if(temp->next==NULL) {
           Node *prevn = temp->prev;
       prevn->next = NULL;
       return head;
       }
       
       if(temp->prev == NULL) {
            Node *nextn = temp->next;
             nextn->prev = NULL;
           return nextn;
       }
       Node *prevn = temp->prev;
       Node *nextn = temp->next;
       prevn->next = nextn;
       nextn->prev = prevn;
       temp->next=NULL;
       temp->prev = NULL;
     
     return head;
    }