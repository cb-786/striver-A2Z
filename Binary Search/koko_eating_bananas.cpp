bool caneat(vector<int> &piles,int h,int k) {
    int sum=0;
    for(int i=0;i<piles.size();i++) {
                sum += (piles[i] + k - 1) / k; 

    }
    return sum<=h;
}




int minEatingSpeed(vector<int>& piles, int h) {
int maxp = 0;
for(int i=0;i<piles.size();i++) {
maxp=max(maxp,piles[i]);
}
int l=1;
int r=maxp;
int mid= (l+r)/2;
while(l<r) {
        mid= (l+r)/2;

if(caneat(piles,h,mid)) {
    r=mid;
}
else{
    l=mid+1;
}
}
return l;
}