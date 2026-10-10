int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size()==1) return cardPoints[0];
        if(k>=cardPoints.size()) {
            int ans=0;
            for(const auto &ele:cardPoints) {
                ans+=ele;
            }
            return ans;
        }
        int ans=0;
        int csum=0;
        for(int i=0;i<k;i++) {
            csum+=cardPoints[i];
        }
        ans=max(ans,csum);
        int i=k-1;
        int j=cardPoints.size()-1;
        while(i<j && j>=0 && j>cardPoints.size()-1-k) {
            csum-=cardPoints[i];
            i--;
            csum+=cardPoints[j];
            j--;
            ans=max(ans,csum);
        }
        return ans;
        
    }