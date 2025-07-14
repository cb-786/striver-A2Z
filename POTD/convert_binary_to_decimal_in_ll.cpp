int getDecimalValue(ListNode* head) {
        ListNode* tmp = head;
        stack<int> q;
        int size=0;
        while(tmp!=NULL) {
            q.push(tmp->val);
            tmp = tmp->next;
        }
        int i=0;
        while(!q.empty()) 
        {
            size += q.top()*pow(2,i);
            q.pop();
            i++;
        }
        return size;
    }