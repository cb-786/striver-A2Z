bool isCompleteTree(TreeNode* root) {
    if (!root) return true;

queue<TreeNode*> q;
q.push(root);
bool nullFound = false;

while (!q.empty()) {
    TreeNode* curr = q.front();
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