int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<pair<int,int>> basket;
        for(const auto &ele : baskets) {
            basket.push_back({ele,0});
        }
        int ans = 0;
        for(int i =0;i<fruits.size();i++) {
            int curr = fruits[i];
            for(int j=0;j<basket.size();j++) {
                if(basket[j].first >= curr && basket[j].second != 1) {
                    ans++;
                    basket[j].second = 1;
                    break;
                }
            }
        }

        return fruits.size() - ans;

    }