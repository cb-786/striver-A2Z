vector<int> firstNegInt(vector<int>& arr, int k) {
    // write code here
    int i=0;
    int j=0;
    queue<int> q;
    vector<int> ans;
    while(j<k) {
        if(arr[j]<0) {
            q.push(j);
        }
        j++;
    }
    
    if (!q.empty()) {
    ans.push_back(arr[q.front()]);
} else {
    ans.push_back(0);
}


while (j < arr.size()) {
    
    if (!q.empty() && q.front() == i) {
        q.pop();
    }

    
    if (arr[j] < 0) {
        q.push(j);
    }

    
    if (!q.empty()) {
        ans.push_back(arr[q.front()]);
    } else {
        ans.push_back(0);
    }

    i++;
    j++;
}
    return ans;
}