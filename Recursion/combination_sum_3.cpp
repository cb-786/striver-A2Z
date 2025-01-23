class Solution {
public:

  

    void answer(vector<vector<int>> &ans,vector<int> &sub,int i,int n,int &k) {

                 if(i>10 || sub.size()>k) return ;

                 if(n==0 && sub.size()==k) {
                    ans.push_back(sub);
                    return ;
                 }

                 for(int j=i;j<=9;j++) {
                    sub.push_back(j);
                    answer(ans,sub,j+1,n-j,k);
                    sub.pop_back();
                   
                 }

                 
    } 

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> sub;
        answer(ans,sub,1,n,k);
        return ans;
    }
};