void rec(int &n,string &curr,vector<string> &ans) {
        if(curr.size()==n) {
            ans.push_back(curr);
            return ;
        }

        curr.push_back('1');
        rec(n,curr,ans);
        curr.pop_back();

        if(curr.empty() || curr.back()!='0') {
            curr.push_back('0');
            rec(n,curr,ans);
            curr.pop_back();
        }
    }



    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr="";
        // for(int j=0;j<1<<n;j++) {
        //     int i=j;
        //     int nn=n;
        //     string curr="";
        //     int cn=2;
        //     while(nn!=0) {
        //         if(cn==0) {
        //             break;
        //         }
        //         if(i&1) {
        //             cn=3;
        //             curr+="1";
        //         }
        //         else 
        //         curr+="0";

        //         i=i>>1;
        //         nn--;
        //         cn--;
        //     }
        //     reverse(curr.begin(),curr.end());
        //     if(cn>0) ans.push_back(curr);
        // }
        // return ans;
        rec(n,curr,ans);
        return ans;
    }