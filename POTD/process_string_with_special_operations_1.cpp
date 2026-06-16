string processStr(string s) {
        string result;
        for(const auto &ele:s) {
            if(ele>='a' && ele<='z') {
            result+=ele;
            }
            if(ele=='*') {
            if(result.empty()) continue;
             result.pop_back();
            }
            if(ele=='#') {
                result+=result;
            }
            if(ele=='%') {
                reverse(result.begin(),result.end());
            }

           
        }
        return result;
    }