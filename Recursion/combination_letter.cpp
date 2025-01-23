class Solution {
public:

    void combi(vector<string> &ans,string &sub,int ind,string &digits,string &mapping[]) {
        if(ind>=digits.size()) {
            ans.push_back(sub);
            return ;
        }


         int digi = digits[ind] - '0';
         string val = mapping[digi];

         for(int i=0;i<val.size();i++) {
            sub.push_back(val[i]);
            combi(ans,sub,ind+1,digits,mapping);
            sub.pop_back();
         }

    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.size()==0) {
            return ans;
        }
        string output;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combi(ans,output,0,digits,mapping);
         return ans;
    }
};