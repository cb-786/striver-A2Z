int maxNumberOfBalloons(string text) {
        vector<int> freq(7,0);
        for(const auto &ele:text) {
            if(ele=='b') {
                freq[0]++;
            }
            if(ele=='a') {
                freq[1]++;
            }
            if(ele=='l') {
                if(freq[2]==freq[3]) {
                    freq[2]++;
                }
                else if(freq[2]>freq[3]) {
                    freq[3]++;
                }
                else {
                    freq[2]++;
                }
            }
            if(ele=='o') {
                if(freq[4]==freq[5]) {
                    freq[4]++;
                }
                else if(freq[4]>freq[5]) {
                    freq[5]++;
                }
                else {
                    freq[4]++;
                }
            }
            if(ele=='n') {
                freq[6]++;
            }
        }
        int ans =INT_MAX;
        for(const auto &ele:freq) {
            ans=min(ans,ele);
        }
        return ans;

    }