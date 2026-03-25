class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for(const auto & ch : s) {
            if(st.empty()) {
                st.push(ch);
                continue;
            }
            if(ch == '(') {
                ans.push_back('(');
                st.push('(');
            }
            if(ch == ')') {
                st.pop();
                if(st.size()!=0)
                ans.push_back(')');
            }
        }
        return ans;
    }
};