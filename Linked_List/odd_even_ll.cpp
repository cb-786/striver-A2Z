ListNode* oddEvenList(ListNode* head) {

        if(head==NULL) {
            return NULL;
        }
        ListNode *od = head;
        ListNode *ev = od->next;
        ListNode *store = ev;

        while(ev!=NULL && ev->next!=NULL) {
            od->next=od->next->next;
            ev->next=ev->next->next;
            od=od->next;
            ev=ev->next;

        }

        od->next = store;
        return head;
    }