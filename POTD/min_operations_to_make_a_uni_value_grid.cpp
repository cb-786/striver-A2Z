int minOperations(vector<vector<int>>& grid, int x) {

    vector<int> elements;
    
    int a = grid[0][0] % x;
    for(auto row : grid) {
        for(auto ele :row) {
            if(ele%x!=a) {
                return -1;
            }

            elements.push_back(ele);
        }
    }

    sort(elements.begin(),elements.end());
    int n1 = elements.size();
    int median = -1;
    
         median = elements[n1/2];
    

     cout << median << endl;
     
    int cnt=0;
    for(auto ele : elements) {
        
            while(ele!=median) {
               
                cnt++;
                
                if(ele>median) {
                    ele-=x;
                }
              
                else {
                    ele+=x;
                }
                
            }
        
    }

    return cnt;
   
}