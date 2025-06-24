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