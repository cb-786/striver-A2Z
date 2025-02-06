 // int rec(vector<int>& arr,map<pair<int,int>,int> &maxi,int s,int e) {
    //     if(s>=e) {
    //         return 0;
    //     }


    //     int ans = INT_MAX;
    //     for(int i=s;i<e;i++) {
    //         ans = min(ans , (maxi[{s,i}] * maxi[{i+1,e}]) + rec(arr,maxi,s,i) + rec(arr,maxi,i+1,e) );

    //     }
    //     return ans;
    // }


    // int topdown(vector<int>& arr,map<pair<int,int>,int> &maxi,int s,int e,vector<vector<int>> &dp) {
    //      if(s>=e) {
    //         return 0;
    //     }

    //     if(dp[s][e]!=-1) {
    //         return dp[s][e];
    //     }
    //     int ans = INT_MAX;
    //     for(int i=s;i<e;i++) {
    //         ans = min(ans , (maxi[{s,i}] * maxi[{i+1,e}]) + topdown(arr,maxi,s,i,dp) + topdown(arr,maxi,i+1,e,dp) );
             
    //     }
    //     dp[s][e] = ans;
    //     return dp[s][e];
    // }


    int bottomup(vector<int>& arr,map<pair<int,int>,int> &maxi) {
              int s = 0;
        int e = arr.size()-1;
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

          for(int j=n;j>=0;j--) {
            for(int k= 0;k<=n-1;k++) {
                if(j>=k) {
                    continue ;
                }
                int ans = INT_MAX;
                for(int i=j;i<k;i++) {

                    ans = min(ans , (maxi[{j,i}] * maxi[{j+1,k}]) + dp[j][i] + dp[i+1][k]);
                }
                dp[j][k] = ans;
            }
          }

          return dp[s][e];

    }



    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;
        for(int i=0;i<arr.size();i++) {
            maxi[{i,i}] = arr[i];
            for(int j=i+1;j<arr.size();j++) {
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
            }
        }

        // int s = 0;
        // int e = arr.size()-1;
        // int n = arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return bottomup(arr,maxi);
    }