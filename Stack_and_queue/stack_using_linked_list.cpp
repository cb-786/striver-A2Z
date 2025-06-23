class MyStack {
    private:
      StackNode *top;
      
    
    public:
      MyStack() {
          top = NULL;
      }
  
      void push(int x) {
          StackNode* newNode = new StackNode(x);
          newNode->next = top;
          top = newNode;
      }
  
      int pop() {
          if (top == NULL) return -1; // or throw error
          StackNode* tmp = top;
          int val = top->data;
          top = top->next;
          delete tmp;
          return val;
      }
  };