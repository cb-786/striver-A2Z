bool valid(stack<char> &st,char c) {
          if(st.empty()) {
            return false;
          }

          if(c=='}' && st.top() == '{') {
            st.pop();
            return true;
          }

          if(c==']' && st.top() == '[') {
            st.pop();
            return true;
          }
        
        if(c==')' && st.top() == '(') {
            st.pop();
            return true;
          }

          
         return false;
          

    }



    bool isValid(string s) {
        stack<char> st;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                 st.push(s[i]);
        }

        else if(s[i]==')' || s[i]=='}' || s[i]==']') {
            bool val = valid(st,s[i]);
            if(val==false) return false;
        }
    }

    if(st.empty())
    return true;

    else return false;
    }