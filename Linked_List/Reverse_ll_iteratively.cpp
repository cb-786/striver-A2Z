 ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        
        
        while(curr!=NULL) {
            ListNode *nextnode = curr->next;
            
            curr->next = prev;
            prev=curr;
            curr=nextnode;
        }

        return prev;

    }