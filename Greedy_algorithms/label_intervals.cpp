vector<int> partitionLabels(string s) {
    vector<pair<int,int>> arr(26,{-1,-1});
    
    for(int i=0;i<s.size();i++) {
        int ind = s[i]-'a';
        
        if(arr[ind].first == -1) {
            arr[ind].first=i;
        }
        
            arr[ind].second = i;
        
    }

  
    
    for(int i=0;i<arr.size();i++) {
        if(arr[i].second == -1) {
             arr.erase(arr.begin()+i,arr.begin()+i+1);
             i=i-1;
        }
    }


   vector<pair<int,int>> ans;
sort(arr.begin(), arr.end());
ans.push_back(arr[0]);

for (int i = 1; i < arr.size(); i++) {
    pair<int,int>& lastInterval = ans.back();
    
    if (arr[i].first > lastInterval.second) {
        ans.push_back(arr[i]);
    }
    else {
        lastInterval.second = max(lastInterval.second, arr[i].second);
    }
}
vector<int> temp;
for(auto i :ans) {
    temp.push_back(i.second-i.first+1);
}
return temp;


}