int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long curr=0;
    long long mini=0;
    long long maxi = 0;
    for(int i=0;i<differences.size();i++) {
        long long ele = curr+differences[i];
        mini = min(mini,ele);
        maxi = max(maxi,ele);
        curr=ele;
    }

    long long lower_k = lower-mini;
    long long upper_k = upper-maxi;
    return (upper_k-lower_k+1 < 0) ? 0 : upper_k-lower_k+1;
}