int countDays(int days, vector<vector<int>>& meetings) {
    vector<vector<int>> ans;


sort(meetings.begin(), meetings.end());


ans.push_back(meetings[0]);


for (int i = 1; i < meetings.size(); i++) {
    
    vector<int>& lastInterval = ans.back();

    
    if (meetings[i][0] > lastInterval[1]) {
        ans.push_back(meetings[i]);
    }
   
    else {
        lastInterval[1] = max(lastInterval[1], meetings[i][1]);
    }
}

   for(auto meeting : ans) {
        cout <<  "[" << meeting[0] << "," << meeting[1] << "]" << endl;
        days = days  - (meeting[1] - meeting[0] +1);
    
   }
   return days;
}