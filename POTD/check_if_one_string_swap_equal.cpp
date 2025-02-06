bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) {
            return false;
        }
        int i=-1;
        int j=-1;
        
        for(int l=0;l<s1.size();l++) {
              if(s1[l]!=s2[l]) {
                   if(i==-1) {
                    i=l;
                   }

                   else if(i!=-1 && j==-1) {
                    j=l;
                   }

                  else  {
                    return false;
                   }
              }
        }
        if(i!=-1 && j==-1) {
            return false;
        }
        if(i!=-1 && j!=-1) {
          swap(s2[i],s2[j]);
          if(s1==s2) return true;
          
        }
        
      if(i==-1 && j==-1) return true;

      return false;
    }
