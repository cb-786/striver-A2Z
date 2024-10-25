 DLLNode* reverseDLL(DLLNode* head) {
        DLLNode *prevn = NULL;
        DLLNode *curr = head;
        DLLNode* nextn = curr->next;
        
        if(head->next == NULL) {
            return head;
        }
        
        curr->next = prevn;
        prevn = curr;
        curr=nextn;
        
        
        
        while(nextn!=NULL) {
            
            if(curr->next == NULL) {
        curr->next = prevn;
        prevn->prev = curr;
        prevn = curr;
        curr->prev = NULL;
        break;
            }
            
            nextn = curr->next;
            curr->next = prevn;
        prevn->prev = curr;
        prevn = curr;
        curr=nextn;
        
        }
        
      
        return curr;
        
        
        
    }