void MyQueue:: push(int x)
{
         QueueNode * newnode = new QueueNode(x);
         if((front==rear) && rear==NULL) {
             front=newnode;
             rear=newnode;
         }
         else {
             rear->next = newnode;
             rear=rear->next;
         }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        if((front==rear) && rear==NULL) return -1;
        
        if(front==rear) {
            int tmp = front->data;
            front=NULL;
            rear=NULL;
            return tmp;
        }
        
        else {
            int tmp = front->data;
            QueueNode * del = front;
            front=front->next;
            delete del;
            return tmp;
        }
}