 ListNode* deleteMiddle(ListNode* head) {
        
        ListNode *tmp = head;
        // stack<ListNode*>st;
        int i =0;
        while(tmp!=NULL) {
            // st.push(tmp);
            tmp=tmp->next;
            i++;
        }
        int size=i;
        if(size<=2) {
            if(size==2) {
                head->next=NULL;
                return head;
            }
            if(size==1 || size==0) {
                return NULL;
            }
        }
        tmp = head;
        i=0;
        while(i!=(size/2)-1) {
            tmp=tmp->next;
            i++;
        }
        ListNode *nn=tmp;
        ListNode *del = tmp->next;
        ListNode *next = (tmp->next)->next;
        del->next=nullptr;
        delete del;
        nn->next = next;
        return head;


    }