long long repairCars(vector<int>& ranks, int cars) {
    long long r=INT_MAX;
    for(int i=0;i<ranks.size();i++) {
        r=min(r,(long long)ranks[i]);
    }    
    long long l=1;
    r=r*cars*cars;
    long long mid=(l+r)/2;
    long long ans=0;
    while(l<r) {
             mid=(l+r)/2;
            ans=0;
            for(int i=0;i<ranks.size();i++) {
                ans += pow((mid/ranks[i]),0.5);
            }
            if(ans>=cars) {
                r=mid;
            }

            else {
                l=mid+1;
            }
    }

    return l;
}