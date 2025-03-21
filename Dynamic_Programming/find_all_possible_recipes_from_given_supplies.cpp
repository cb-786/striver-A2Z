bool canbemade(vector<string>& recipes,vector<string> &supplies,vector<vector<string>> &ingredients,int i,vector<int> &dp) {
    if (i >= recipes.size()) {  
return false;
}

if (dp[i] == 1) {  
return true;
}
if (dp[i] == 0) {  
return false;
}

if(dp[i]==2) {
return false;
}

dp[i] = 2;

vector<string> curing = ingredients[i];
vector<bool> ing(curing.size(), 0);

for (int j = 0; j < curing.size(); j++) {
for (int k = 0; k < supplies.size(); k++) {
if (supplies[k] == curing[j]) {
    ing[j] = 1;
    break;
}
}

if (ing[j] != 1) {
for (int k = 0; k < recipes.size(); k++) {
    if (recipes[k] == curing[j]) {
        vector<string> recking = ingredients[k];
        for (int l = 0; l < recking.size(); l++) {
            if (recipes[i] == recking[l]) {
                dp[i] = false;
                return false;
            }
        }
        ing[j] = canbemade(recipes, supplies, ingredients, k, dp);
    }
}
}

if (ing[j] == 0) {
dp[i] = false;
return false;
}
}

dp[i] = 1;  
return true;
}

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
vector<string> ans;
vector<int> dp(recipes.size(),-1);
for(int i=0;i<recipes.size();i++) {
        if(canbemade(recipes,supplies,ingredients,i,dp)) {
            ans.push_back(recipes[i]);
        }
}
return ans;
}