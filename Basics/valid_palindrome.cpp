  bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++) {
            if(s[i]>='A' && s[i]<='Z') {
                s[i] = s[i]-'A' + 'a';
            }

            if(s[i] >= 'a' && s[i]<='z') {
                continue;
            }
               
               if(s[i]>='0' && s[i]<='9') {
                continue;
               }

            else {
                s.erase(s.begin()+i);
                i--;
            }
        }
        int i=0;
        int j = s.size()-1;
        
        while(i<j) {
            if(s[i]!=s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;


    }