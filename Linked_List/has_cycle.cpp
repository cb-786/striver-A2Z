bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast!=NULL) {
            fast=fast->next;
            if(fast==slow) return true;
            if(fast!=NULL) {
                fast=fast->next;
                slow=slow->next;
            }
        }

        return false;

    }