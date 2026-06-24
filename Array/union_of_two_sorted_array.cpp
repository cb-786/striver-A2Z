vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i=0;
        int j=0;
        int idx=0;
        vector<int> arr;
        while(i<a.size() && j<b.size()) {
            if(a[i]==b[j]) {
                if(idx==0) {
                    arr.push_back(a[i]);
                    i++;
                    j++;
                    idx++;
                    continue;
                }
                else {
                    if(arr[idx-1]==a[i]) {
                        i++;
                        j++;
                        continue;
                    }
                    else {
                        arr.push_back(a[i]);
                        i++;
                        j++;
                        idx++;
                        continue;
                    }
                }
            }
            if(a[i]<b[j]) {
                if(idx==0) {
                    arr.push_back(a[i]);
                    i++;
                    idx++;
                    continue;
                }
                else {
                    if(arr[idx-1]==a[i]) {
                        i++;
                        continue;
                    }
                    else {
                        arr.push_back(a[i]);
                        i++;
                        idx++;
                        continue;
                    }
                }
            }
            if(a[i]>b[j]) {
                if(idx==0) {
                    arr.push_back(b[j]);
                    j++;
                    idx++;
                    continue;
                }
                else {
                    if(arr[idx-1]==b[j]) {
                        j++;
                        continue;
                    }
                    else {
                        arr.push_back(b[j]);
                        j++;
                        idx++;
                        continue;
                    }
                }
            }
        }
        if(j<b.size()) {
            for(;j<b.size();j++) {
                if(idx==0) {
                    arr.push_back(b[j]);
                    idx++;
                    continue;
                }
                else {
                    if(arr[idx-1]==b[j]) {
                        continue;
                    }
                    else {
                        arr.push_back(b[j]);
                        idx++;
                        continue;
                    }
                }
            }
        }
        else {
            for(;i<a.size();i++) {
               if(idx==0) {
                    arr.push_back(a[i]);
                    idx++;
                    continue;
                }
                else {
                    if(arr[idx-1]==a[i]) {
                        continue;
                    }
                    else {
                        arr.push_back(a[i]);
                        idx++;
                        continue;
                    }
                }
            }
        }
        return arr;
    }