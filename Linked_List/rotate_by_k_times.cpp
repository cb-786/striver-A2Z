int getCount(ListNode* head) {
        int len=0;
        ListNode *temp = head;
        while(temp!=NULL) {
            temp=temp->next;
            len++;
        }
        
        return len;
    }


   



    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) {
            return head;
        }

        
        int trav=0;
        int n = getCount(head);
        if(k>n) {
              k=k%n;
        }
        if(k==n || k==0) return head;

        
        
        ListNode *temp = head;
        
             trav = n - k;
        

      
             while(trav!=1 && temp!=NULL) {
                temp=temp->next;
                trav--;
             }

             ListNode *h2 = temp->next;
             temp->next=NULL;
             ListNode *t2 = h2;
             while(t2->next!=NULL && t2!=NULL) {
                t2=t2->next;
             }
             t2->next = head;
             head=h2;
             return head;
        

        
         

    }