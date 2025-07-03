bool complete(Node *tree) {
    if (!tree) return true;

   queue<Node*> q;
   q.push(tree);
   bool nullFound = false;

   while (!q.empty()) {
       Node* curr = q.front();
       q.pop();

       if (curr->left) {
           if (nullFound) return false;  // found node after null -> not complete
           q.push(curr->left);
       } else {
           nullFound = true;
       }

       if (curr->right) {
           if (nullFound) return false;
           q.push(curr->right);
       } else {
           nullFound = true;
       }
   }

   return true;
 }
 
 bool rec(Node* tree) {
   

   if(tree==NULL) {
           return true;
   }
   
   if(tree->right == NULL && tree->left==NULL) {
       return true;
   }

   bool left = rec(tree->left);
   bool right = rec(tree->right);

   if (tree->left) {
       if (tree->left->data > tree->data) {
           return false;
       }
   }

   if (tree->right) {
       if (tree->right->data > tree->data) {
           return false;
       }
   }

   return (left && right);
}

bool isHeap(Node* tree) {
   return (rec(tree) && complete(tree));
}