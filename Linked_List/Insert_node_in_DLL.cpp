Node *addNode(Node *head, int pos, int data) {
     Node *newnode = new Node(data);   
     Node *temp = head;
     
     
     while(pos!=0) {
         temp = temp->next;
         pos--;
     }
     
     if(temp->next == NULL) {
         temp->next = newnode;
     newnode->prev = temp;
     return head;
     }
     Node *nexter = temp->next;
     temp->next = newnode;
     newnode->prev = temp;
     newnode->next = nexter;
     nexter->prev = newnode;
     
     return head;
    }