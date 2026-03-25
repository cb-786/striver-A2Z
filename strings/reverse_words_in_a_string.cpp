class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
        for(const auto &ch : s) {
            if(ch == ' ' && !word.empty()) {
                // cout << word << endl;
                st.push(word);
                word.clear();
                continue;
            }
            if(ch == ' ' && word.empty()) {
                continue ;
            }
            word.push_back(ch);
        }
        
        if(!word.empty())
        st.push(word);
        s.clear();
        while(!st.empty()) {
            s+= st.top();
            st.pop();
            if(!st.empty())
            s.push_back(' ');
        }
       
        return s;
    }
};