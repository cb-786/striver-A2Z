int possibleStringCount(string word) {
    int cnt = 1;
    int i=0;
    while(i<word.size()) {
        while(i!=word.size()-1 && word[i]==word[i+1]) {
            i++;
            cnt++;
        }
        i++;
    }

    return cnt;
}