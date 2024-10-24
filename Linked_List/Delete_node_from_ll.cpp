void deleteNode(ListNode* node) {

     node->val = (node->next)->val;

     ListNode* temp = node->next;
     node->next = temp->next;
     temp->next = NULL;


    }