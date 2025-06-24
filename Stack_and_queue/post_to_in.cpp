bool isop(char c) {
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') return 1;
    
    return 0;
}
 

  string postToInfix(string s) {
      
      stack<string> st;
      for(auto ch:s) {
          if(isop(ch)) {
              string op2 = st.top();st.pop();
              string op1 = st.top();st.pop();
              
              string ans = "(" + op1 + string(1, ch) + op2 + ")";

              
              st.push(ans);
          }
          
          else {
          
              st.push(string(1,ch));
          }
      }
      return st.top();
      
  }