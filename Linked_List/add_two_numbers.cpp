ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        int sum=0;
        int carry =0;
        ListNode *temp = l1;
        ListNode *temp2 = l2;
       
        while(temp!=NULL && temp2!=NULL) {

             sum = (temp->val + temp2->val) +carry;
              if(sum>9 && temp->next==NULL && temp2->next==NULL) {
                        carry =sum/10;
                        temp->val = sum%10;
                        ListNode *newnode = new ListNode(carry);
                        temp->next = newnode;
                        return l1;
                    }
            if(sum>9) {
                temp->val = sum%10;
                temp2->val = sum%10;
                carry = sum/10;
            
            }

            else {
                temp2->val = sum;
                temp->val = sum;
                carry=0;
            }
             
             temp=temp->next;
             temp2=temp2->next;
        
        }

        if(temp==NULL && temp2==NULL && carry==0) {
               return l1;
        }





        else if(carry!=0) {

           if(temp==NULL) {
            flag=1;
            while(carry!=0 && temp2!=NULL) {
                if(temp2->next==NULL && carry!=0) {
                    temp2->val+=carry;
                     if(temp2->val>9) {
                        carry = temp2->val/10;
                        temp2->val = temp2->val%10;
                        ListNode *newnode = new ListNode(carry);
                        temp2->next = newnode;
                        return l2;
                    }
                    return l2;
                }
             sum = temp2->val  +carry;
            if(sum>9) {
                temp2->val = sum%10;
                carry = sum/10;
            
            }

            else {

                temp2->val = sum;
                carry = 0;

            }
             
            
             temp2=temp2->next;
            }

            return l2;
           
           }




           else {
            while(carry!=0 && temp!=NULL) {
                if(temp->next==NULL && carry!=0) {
                    temp->val+=carry;
                    if(temp->val>9) {
                        carry = temp->val/10;
                        temp->val = temp->val%10;
                        ListNode *newnode = new ListNode(carry);
                        temp->next = newnode;
                        return l1;
                    }
                    return l1;
                }
                  sum = temp->val + carry;
            if(sum>9) {
                temp->val = sum%10;
                carry = sum/10;
            
            }

            else {
                temp->val = sum;
                carry=0;
                break;
            }
             
             temp=temp->next;
            }
           return l1;
           }
        }

        else {
            if(temp!=NULL) {
                return l1;
            }

            else {
                return l2;
            }
        }
      

      if(flag==0) return l1;

      else {
        return l2;
      }
        
    }