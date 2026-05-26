class Solution {
public:
    
    // bool rec(string &s,int& minjump,int &maxjump,int i,bool &ans) {
    //     if(i==s.size()-1) return true;

    //     if(i>= s.size()) return false;

    //     for(int j = minjump;j<=maxjump;j++) {
    //         if((i+j)<s.size() && s[i+j]=='0') {
    //             ans = ans | rec(s,minjump,maxjump,i+j,ans);
    //             if(ans == true) return true;
    //         }
    //     }

    //     return ans;
    // }

    // bool topdown(string &s,int &minjump,int &maxjump,int i,vector<int> &dp) {
    //     if(i==s.size()-1) return true;

    //     if(i>= s.size()) return false;

    //     if(dp[i]!=2) return dp[i];

    //     bool localans = 0;
    //     for(int j = minjump;j<=maxjump;j++) {
    //         if((i+j)<s.size() && s[i+j]=='0') {
    //             localans = localans | topdown(s,minjump,maxjump,i+j,dp);
    //             if(localans==true) {
    //                 dp[i] = localans;
    //                 return true;
    //                 }
    //         }
    //     }
    //     dp[i] = localans;
    //     return dp[i];
    // }

    // bool bottomup(string &s,int &minjump,int &maxjump,int i,vector<bool> &dp) {
    //     dp[s.size()-1] = 1;
    //     for(int i = s.size()-2;i>=0;i--) {
    //             if(s[i]=='1') continue;
    //         for(int j = minjump;j<=maxjump;j++) {
    //             if((i+j)<s.size() && dp[i+j]==1) {
    //                 dp[i]=1;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[0];

    // }


    bool canReach(string s, int minJump, int maxJump) {
            int n = s.size();
    
    
    if (s[n - 1] == '1') return false; 

    
    vector<bool> history(n, false);
    history[0] = true; 
    
  
    int valid_stones_in_light = 0; 

    
    for (int i = 1; i < n; i++) {
        
        int entering_index = i - minJump;
        if (entering_index >= 0 && history[entering_index] == true) {
            valid_stones_in_light++;
        }
        
        
        int leaving_index = i - maxJump - 1;
        if (leaving_index >= 0 && history[leaving_index] == true) {
            valid_stones_in_light--;
        }
        
       
        if (s[i] == '0' && valid_stones_in_light > 0) {
            history[i] = true;
        }
    }
    
    
    return history[n - 1];
    }
};