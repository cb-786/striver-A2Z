bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

    string preToInfix(string s) {
        stack<string> st;

    // Traverse from right to left
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];

        if (isOperator(c)) {
            // Pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Form a valid infix expression
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        } else {
            // Operand: push as string
            st.push(string(1, c));
        }
    }

    return st.top();
        
    }
    
    int priority(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}
string infixToPostfix(string& s) {
    // code here
    int i=0;
    stack<char>st;
    int n=s.length();
    string ans="";
    while(i<n){
        
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            ans+=s[i];
        }
        
        else if(s[i]=='(')
        st.push(s[i]);
        
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        
        else{
            while(!st.empty()&& (priority(s[i])<=priority(st.top()))){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    
    return ans;
}
  
  
  
    string preToPost(string pre_exp) {
        string in = preToInfix(pre_exp);
        return infixToPostfix(in);
    }