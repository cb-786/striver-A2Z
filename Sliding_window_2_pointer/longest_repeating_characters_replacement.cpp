int characterReplacement(string s, int k) {
    unordered_map<char,int> freq;
    int maxfreq=0;
    int i=0;
    int j=0;
    int ans=0;
    int f=0;
    while(j<s.size()) {
            freq[s[j]]++;
            if(freq[s[j]] > maxfreq) {
                maxfreq=freq[s[j]];
                f=j;
            }
            j++;

            if(j-i - maxfreq <=k) {
                ans=max(ans,j-i);
            }

            else {
                    while(j-i - maxfreq > k) {
                        
                        freq[s[i]]--;
                       
                        i++;
                    }
            }
    }
    return ans;
}