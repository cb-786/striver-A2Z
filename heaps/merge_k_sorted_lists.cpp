ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int , vector<int>, greater<int>> pq;
    for(auto tmp : lists) {
        while(tmp!=NULL) {
                pq.push(tmp->val);
                tmp=tmp->next;
        }
    }
    
     if (pq.empty()) return nullptr;

    ListNode *ans =  new ListNode(pq.top());
    ListNode *tmp = ans;
    pq.pop();
    while(!pq.empty()) {
        ListNode * nextNode = new ListNode(pq.top());
        tmp->next = nextNode;
        tmp=tmp->next;
        pq.pop();
    }
    return ans;

}