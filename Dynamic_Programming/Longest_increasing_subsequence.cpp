int solveUsingRecursion(vector<int>& num, int curr, int prev,vector<vector<int>> &dp) { 
    if(curr >= num.size()) { 
    return 0;
}

int include = 0;

if (prev == -1 || num[curr] > num[prev]) { 
        include = 1 + solveUsingRecursion(num, curr+1, curr); 
    }

int exclude = 0 + solveUsingRecursion(num, curr+1, prev);

int ans = max(include, exclude);
return ans;
}


int solveUsingTabulation(vector<int>& num) {
int n = num.size();
vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); 

for(int curr_index = n-1; curr_index >= 0; curr_index--) {
for(int prev_index = curr_index-1; prev_index >= -1; prev_index--) {
int include = 0;
if(prev_index == -1 || num[curr_index] > num[prev_index]) {
include = 1 + dp[curr_index+1][curr_index+1]; 
}
int exclude = 0 + dp[curr_index+1][prev_index+1];
dp[curr_index][prev_index+1] = max(include, exclude);
}
}

return dp[0][0];
}


int solveUsingTabulationSO(vector<int>& num) {
int n = num.size();
vector<int> curr(n+1,0);
vector<int> next(n+1,0); 

for(int curr_index = n-1; curr_index >= 0; curr_index--) {
for(int prev_index = curr_index-1; prev_index >= -1; prev_index--) {
int include = 0;
if(prev_index == -1 || num[curr_index] > num[prev_index]) {
include = 1 + next[curr_index+1]; 
}
int exclude = 0 + next[prev_index+1];
curr[prev_index+1] = max(include, exclude);
}
next=curr;
}

return next[0];
}




int bs(vector<int>& num) {
int n = num.size();
vector<int> ans;
ans.push_back(num[0]);

for(int i=1;i<num.size();i++) {
if(num[i]>ans.back()) {
    ans.push_back(num[i]);
}

else {
    int index = lower_bound(ans.begin(),ans.end(),num[i]) - ans.begin();
    ans[index] = num[i];
}
}

return ans.size();
}

int lengthOfLIS(vector<int>& nums) {
// int curr= 0;
// int prev=-1;
// vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
int ans = bs(nums);
return ans;
}