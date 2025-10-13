vector<string> removeAnagrams(vector<string>& words) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=1;i<words.size();i++) {
                for(const auto &ch : words[i]) {
                    freq1[ch-'a']++;
                }
                for(const auto &ch : words[i-1]) {
                    freq2[ch-'a']++;
                }

                if(freq1 == freq2) {
                    words.erase(words.begin()+i);
                    i--;
                }
                freq1.clear();
                freq2.clear();
                freq1.resize(26,0);
                freq2.resize(26,0);
        }
        return words;
    }