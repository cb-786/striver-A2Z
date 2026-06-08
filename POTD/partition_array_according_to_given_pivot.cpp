vector<int> pivotArray(vector<int>& nums, int pivot) {
        deque<int> dq;
        stack<int> s;
        int np=0;
        for(const auto &ele:nums) {
            if(ele==pivot) np++;
        }
        while(np!=0) {
            dq.push_back(pivot);
            np--;
        }
        for(const auto &ele:nums) {
            if(ele==pivot) continue;

            if(ele<pivot) s.push(ele);

            if(ele>pivot) dq.push_back(ele);
        }

        nums.clear();
        while(!s.empty()) {
            dq.push_front(s.top());
            s.pop();   
        }
        while(!dq.empty()) {
            nums.push_back(dq.front());
            dq.pop_front();
        }
        return nums;

    }