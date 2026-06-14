int pairSum(ListNode* head) {
        int ans = INT_MIN;
        ListNode *tmp = head;
        int i =0;
        stack<int> st;
        while(tmp!=NULL) {
            st.push(tmp->val);
            tmp=tmp->next;
            i++;
        }
        int size = i;
        while(i!=(size/2)) {
            ans=max(ans,head->val+st.top());
            st.pop();
            head=head->next;
            i--;
        }
        return ans;
    }