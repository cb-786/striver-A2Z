class StockSpanner {
    public:
        stack<pair<int,int>> st;
        
        StockSpanner() {
            
        }
        
        int next(int price) {
    
           int cnt=1;
    
            if(!st.empty() && price < st.top().first) {
                cnt=1;
                st.push({price,1});
                return cnt;
            }
    
            while(!st.empty() && price>=st.top().first) {
                cnt+=st.top().second;
                st.pop();
            }
    
            st.push({price,cnt});
            return cnt;
    
        }
    };