 bool valid(stack<char>& st, char c) {
    if (st.empty()) {
        return false;
    }
    // Mapping for matching brackets
    char top = st.top();
    if ((c == ')' && top == '(') || 
        (c == '}' && top == '{') || 
        (c == ']' && top == '[')) {
        st.pop();
        return true;
    }
    return false;
}




    bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (!valid(st, c)) {
                return false;
            }
        }
    }
    return st.empty();
}




















    void par(int n, vector<string>& ans, string sub, int open, int close) {
    // If the current string reaches 2*n, add to the result
    if (sub.size() == 2 * n) {
        ans.push_back(sub);
        return;
    }

    // Add an open parenthesis if there are remaining open slots
    if (open < n) {
        par(n, ans, sub + '(', open + 1, close);
    }

    // Add a closing parenthesis only if it won't unbalance the string
    if (close < open) {
        par(n, ans, sub + ')', open, close + 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    par(n, ans, "", 0, 0);
    return ans;
}