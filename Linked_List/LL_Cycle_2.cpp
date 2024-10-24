 ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int flag=0;
        while(fast!=NULL && fast->next) {
            fast=fast->next;
             fast=fast->next;
               
                slow=slow->next;
            if(fast==slow) {
                flag=1;
                break;
                }
            
        }

          if(flag==1) {

            slow=head;

            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }

            return fast;

          }

        return NULL;
    }