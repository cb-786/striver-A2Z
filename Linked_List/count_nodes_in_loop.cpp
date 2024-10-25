int countNodesinLoop(Node *head) {
        
      Node *slow = head;
      Node *fast = head;
      int flag = 0;
      int cnt=0;
      while(fast!=NULL) {
          
          fast=fast->next;
          if(fast==NULL) break;
          fast=fast->next;
          slow=slow->next;
          
          
          if(fast==slow) {
              flag=1;
              slow=head;
              while(fast!=slow) {
                  fast=fast->next;
                  slow=slow->next;
              }
              break;
          }
          
          
          
      }
      
      if(flag==1){
          
          if(fast->next == slow) {
          return 1;
      }
      
      fast=fast->next;
      cnt++;
      while(fast!=slow) {
          cnt++;
          fast=fast->next;
      }
      }
      
      
      
      return cnt;
      
      
      
    }