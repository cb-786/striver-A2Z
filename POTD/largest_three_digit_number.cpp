string largestGoodInteger(string num) {
        int i =0;
        int ans = INT_MIN;
        while(i<num.size()-2) {
            if(num[i+1] == num[i+2] && num[i+1] == num[i]) {
                ans = max(ans,(int)num[i]);
            }
            i++;
        }

        if(ans == INT_MIN) return "";

        string k;
        k.push_back(ans);
        k.push_back(ans);
        k.push_back(ans);
        return k;


       
    }