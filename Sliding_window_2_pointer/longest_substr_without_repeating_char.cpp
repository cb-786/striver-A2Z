int lengthOfLongestSubstring(string s) {
    vector<bool>count(256,0);
    int first=0,second=0,size=0;
    while(second<s.size()){
            while(count[s[second]]){
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            size=max(size,second-first+1);
            second++;
        }
    return size;
}