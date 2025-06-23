stack<int> s1;
stack<int> s2;
MyQueue() {
}

void push(int x) {
    s1.push(x);
}

int pop() {
if(empty()) {
    return -1;
}

    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    int tmp = s2.top();
    s2.pop();
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    
    return tmp;

}

int peek() {
if(empty()) return -1;

while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    int tmp = s2.top();
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    return tmp;

}

bool empty() {
if(s1.empty() && s2.empty()) return true;

return false;
}
};