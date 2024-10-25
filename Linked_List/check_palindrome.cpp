ListNode* middle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast!=NULL) {
        fast=fast->next;
        if(fast!=NULL) {
            fast=fast->next;
            if(fast==NULL) break;
            slow=slow->next;
        }
    }

    return slow;
   }

    ListNode* rev(ListNode *head) {
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

    bool isPalindrome(ListNode* head) {

        ListNode *mid =  middle(head);
        ListNode *temp = head;
        ListNode *head2 = mid->next;
        mid->next = NULL;
        head2 = rev(head2);

        while(head2 != NULL) {
            if(head2->val != temp->val) return false;

            head2=head2->next;
            temp=temp->next;
        }

        return true;

    }