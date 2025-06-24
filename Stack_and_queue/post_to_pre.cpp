bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
    string postToPre(string s) {
        // Write your code here
        stack<string> st;

    for (char c : s) {
        if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = c + op1 + op2;
            st.push(expr);
        } else {
            st.push(string(1, c)); // single-character operand
        }
    }

    return st.top();
    }