void del(ListNode* &head, ListNode* &tail, int position,int len) {
  //empty list
  if(head == NULL) {
    cout << "Cannot delete, coz LL is empty" << endl;
    return;
  }

  if(head == tail) {
    //single element
    ListNode* temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
    return;
  }

 

  //delete from head
  if(position == 1) {
    //first node ko delete kardo
    ListNode* temp = head;
    head = head->next;
    //head = temp->next;
    temp->next = NULL;
    delete temp;
  }
  else if(position == len) {
    //last node ko delete krdo\

    //find prev
    ListNode* prev = head;
    while(prev -> next != tail ){
      prev = prev -> next;
    }

    //prev node ka link null karo
    prev -> next = NULL;

    //node delete kro
    delete tail;

    //update tail
    tail = prev;

  }
  else {
    //middle me koi node ko delete krna h 

    //step1: set prev/curr pointers
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(position != 1) {
      position--;
      prev = curr;
      curr = curr->next;
    }

    //step2: prev -> next me curr ka next node add kro
    prev->next = curr->next;

    //step3: node isolate krdo
    curr->next = NULL;
    //step4: delte node
    delete curr;

  }

}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * temp = head;
        int cnt=1;
        while(temp->next!=NULL) {
            cnt++;
            temp=temp->next;
        }


        int pos = cnt-n+1;

        del(head,temp,pos,cnt);
        return head;


    }