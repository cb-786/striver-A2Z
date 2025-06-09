vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    if(numRows==1) return ans;

    ans.push_back({1,1});
    if(numRows==2) return ans;

    
    while(numRows!=2) {
        vector<int> tmp;
        tmp.push_back(1);
        vector<int> ba = ans.back();
        for(int i=0;i<ba.size()-1;i++) {
            tmp.push_back(ba[i]+ba[i+1]);
        }
        tmp.push_back(1);
        ans.push_back(tmp);
        numRows--;
    }
    return ans;
}