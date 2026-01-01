vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i>=0;i--) {
            if(digits[i]!=9) {
                digits[i]+=1;
                return digits;
            }
            
            digits[i] = 0;

            if(i==0) {
                digits[i]=0;
                digits.push_back(1);
                swap(digits[0],digits.back());
                return digits;
            }

           
        }
        return digits;
    }