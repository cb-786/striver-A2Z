 void rev(vector<char> &s,int i) {
        if(i>=s.size()/2) {
            return ;
        }

        swap(s[i],s[s.size()-i-1]);

        rev(s,i+1);

        return ;
    }


    void reverseString(vector<char>& s) {
        rev(s,0);
        return  ;
    }