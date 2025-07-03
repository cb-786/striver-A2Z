char kthCharacter(int k) {
    string word = "a";
    while(word.length() < k) {
        int len = word.length();
        for(int i=0;i<len;i++) {
            char r = word[i];
            if(r=='z') {
                word+= 'a';
            }

            else {
                word += ++r;
            }
        }
    }
    if(k-1 < word.size())
    return word[k-1];

    else return '-1';
}