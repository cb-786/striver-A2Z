int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
    int flag1=0;
    
    int ans=1;
    for(int i=0;i<wordList.size();i++) {
       

        if(wordList[i]==endWord) {
            flag1++;
        }
    }

    if(flag1==0) {
        return 0;
    }

   
    
    unordered_set<string> st(wordList.begin(),wordList.end());
    st.erase(beginWord);
    

    queue<string> q;
   
    q.push(beginWord);
    q.push("-1");
    while(!q.empty()) {
        
        string front = q.front();
        q.pop();

        if(front == "-1") {
            if(q.empty()) {
                return 0;
            }
           
            ans++;
            q.push("-1");
            continue;
        }
            for(int i=0;i<front.size();i++) {
                string tmp = front;
                for(char a = 'a';a<='z';a++) {
                    
                   front[i] = a;
                   if(front==tmp) continue;
                   
                    if(front==endWord) {
                        return ans+1;
                    }

                    if(st.find(front)!=st.end()) {
                        st.erase(front);
                        q.push(front);
                        
                    }
                   
                }
                front = tmp;
            }
    }

    return 0;

    



}