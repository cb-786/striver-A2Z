ListNode* deleteMiddle(ListNode* head) {
         ListNode *slow=head;
       ListNode *fast = head;
       ListNode *prev = NULL;
       while(fast!=NULL ) {
         fast = fast->next;
         if(fast!=NULL) {
            fast=fast->next;
           
            prev=slow;
            slow=slow->next;
            
         }
       }
         if(prev==NULL) {
            head=head->next;
            return head;
         }
       prev->next=slow->next;
       slow->next=NULL;
       return head;
    }