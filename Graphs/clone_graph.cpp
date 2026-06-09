class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
       vector<int> vis(101,0);
       Node *newnode = new Node(node->val);
    //    Node *working = newnode;
       vector<Node*> nodes(101,nullptr);
       nodes[1]=newnode;
       stack<Node*> st;
       st.push(node);
       while(!st.empty()) {
            Node *oldnode = st.top();
            // vis[oldnode->val]=1;
            st.pop();
           
                if(nodes[oldnode->val]==nullptr) {
                    Node *currpushing = new Node(oldnode->val);
                    nodes[oldnode->val]=currpushing;
                }
            for(const auto &lst : oldnode->neighbors) {
                

               if(nodes[lst->val]!=nullptr) {
                 nodes[oldnode->val]->neighbors.push_back(nodes[lst->val]);
               }
               else {
                 Node *nbr = new Node(lst->val);
                 nodes[lst->val]=nbr;
                 nodes[oldnode->val]->neighbors.push_back(nodes[lst->val]);
                 st.push(lst);
               }
              
                
            }



       }
        return newnode;
    }
};