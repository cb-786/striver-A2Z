ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode *tmp1=headA;
        // ListNode *tmp2=headB;
        // if(tmp1==tmp2) return headA;

        // while(tmp1!=NULL) {
        //     while(tmp2!=NULL) {
        //         if(tmp2==tmp1->next) {
        //             return tmp1->next;
        //         }
        //         tmp2=tmp2->next;
        //     }
        //     tmp1=tmp1->next;
        //     tmp2=headB;
        // }
        // return NULL;
         
        if (headA == NULL || headB == NULL) return NULL;

    ListNode *ptrA = headA;
    ListNode *ptrB = headB;

    // Loop continues until the two pointers meet
    while (ptrA != ptrB) {
        // If ptrA reaches the end, switch to headB; otherwise, move to next node
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        
        // If ptrB reaches the end, switch to headA; otherwise, move to next node
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    // Either they met at the intersection node, or both hit NULL (no intersection)
    return ptrA;



    }