ListNode* sortList(ListNode* head) {

        if(head==NULL) return NULL;
        
        ListNode *temp = head;
        queue<int> q;
        for(;temp!=NULL;temp=temp->next) {
           q.push(temp->val);
        }


    vector<int> tmp;
    while (!q.empty()) {
        tmp.push_back(q.front());
        q.pop();
    }

   sort(tmp.begin(), tmp.end()); // Sorting the vector

    for (int x : tmp) {
        q.push(x);
    }

        temp=head;
        for(;temp!=NULL;temp=temp->next) {
            
            temp->val=q.front();
            q.pop();

        }

        return head;

    }