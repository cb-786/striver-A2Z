class twoStacks {
    public:
      
      int *arr;
      int top1,top2;
      twoStacks() {
          arr = new int[100];
           top1 = -1;
           top2 = 100;
      }
  
      // Function to push an integer into the stack1.
      void push1(int x) {
          
              if(top2-top1==1) {
                  return ;
              }
              top1++;
              arr[top1] = x;
              
          
      }
  
      // Function to push an integer into the stack2.
      void push2(int x) {
         if(top2-top1==1) {
                  return ;
              }
              top2--;
              arr[top2]=x;
          
      }
  
      // Function to remove an element from top of the stack1.
          
      int pop1() {
          if(top1!=-1) {
              int tmp = arr[top1];
              arr[top1] = 0;
              top1--;
              return tmp;
          }
          return -1;
      }
  
          
      // Function to remove an element from top of the stack2.
      int pop2() {
          if(top2!=100) {
              int tmp = arr[top2];
              arr[top2] = 0;
              top2++;
              return tmp;
          }
          return -1;
      }
  };