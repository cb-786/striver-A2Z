string mapWordWeights(vector<string>& words, vector<int>& weights) {
          string ans;
          for(const auto &ele:words) {
          int curstrsum=0;
           for(const auto &chr:ele) {
              curstrsum += weights[chr-'a'];
           }
           char ch = 25-(curstrsum%26)+'a';
            ans.push_back(ch);
          }
          return ans;
          

    }