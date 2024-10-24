ListNode* rev(ListNode *prev,ListNode *curr) {
         if(curr==NULL) {
                return prev;
         }

          ListNode* next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;

          return rev(prev,curr);


   }





    ListNode* reverseList(ListNode* head) {

       return rev(NULL,head);

    }