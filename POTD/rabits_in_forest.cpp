int numRabbits(vector<int>& answers) {
    sort(answers.begin(),answers.end());
    int ans=0;
    int i=0;
    while(i<answers.size()) {

        if(answers[i]==0) {
            ans++;
            i++;
            continue;
        }
        int currcnt=0;
        
        while(i<=answers.size()-2 && answers[i] == answers[i+1]) {
            currcnt++;
            if(currcnt==answers[i]+1) {
                ans+=currcnt;
                currcnt=0;
            }
            
            i++;
        }
        ans+=answers[i]+1;
        i++;
    }
    return ans;
}