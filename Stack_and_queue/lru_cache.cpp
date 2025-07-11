class node {
    public:
    int key;
    int val;
    node *next;
    node *prev;
    node (int key, int val) {
        this-> key = key;
        this-> val = val;
    }
};

node *head = new node(-1,-1);
node *tail = new node(-1,-1);
int capacity;
unordered_map<int,node *> m;


LRUCache(int capacity) {
    this->capacity= capacity;
    head->next = tail;
    tail ->prev = head;
}


void addnode(node * newnode) {
node * temp = head -> next;
newnode -> next = temp;
newnode -> prev = head;
head -> next = newnode;
temp -> prev = newnode;
}

void deletenode(node * delnode) {
node * delprev = delnode -> prev;
node * delnext = delnode -> next;
delprev -> next = delnext;
delnext -> prev = delprev;
}



int get(int key) {
    if(m.find(key) != m.end()) {
        node *resnode = m[key];
        int res = resnode->val;
        m.erase(key);
        deletenode(resnode);
        addnode(resnode);
        m[key] = head->next;
        return res;
        
    }

    return -1;


}

void put(int key, int value) {
    if(m.find(key) != m.end()) {
        node *resnode = m[key];
        m.erase(key);
        deletenode(resnode);
    }

    if(m.size() == capacity) {
        m.erase(tail->prev->key);
        deletenode(tail->prev);
    }

    addnode(new node(key,value));
    m[key] = head->next;

}
};