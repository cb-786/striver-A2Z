int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
    int i=0;
    int f=0;
    while(i<gas.size()) {
        int c = 0;
        c+=gas[i];
        c-=cost[i];
        
        int j =  (i==gas.size()-1) ? 0 : i+1;
        if(j==0) f=1;
        while(c>=0) {
            if(j>=gas.size()) {
                j=0;
                f=1;
            }

            if(j==i) return i;
            c+=gas[j];
            c-=cost[j];
           
            j++;
        }
        if(f==1) break;
        i=j;
    }
    return -1;

}