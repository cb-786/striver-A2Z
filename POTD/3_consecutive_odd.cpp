bool threeConsecutiveOdds(vector<int>& arr) {
    if(arr.size()<3) {
        return false;
    }
    int i=0;
    int j=2;
    while(j<arr.size()) {
        if(arr[i]%2==1 && arr[i+1]%2==1 && arr[i+2]%2==1) {
            return true;
        }
        i++;
        j++;
    }
    return false;
}q