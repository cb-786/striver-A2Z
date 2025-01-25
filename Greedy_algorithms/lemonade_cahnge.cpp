bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twen = 0;
        for(int i=0;i<bills.size();i++) {
            if(bills[i] ==5) {
                five++;
                continue;
            }

            if(bills[i] == 10) {
                   if(five==0) return false;

                   else {
                    ten++;
                    five--;
                   }
            }

            if(bills[i]==20) {
                if(five==0) return false;

                else if(five >= 1 && ten >=1) {
                    five--;
                    ten--;
                    twen++;
                }

                else if(five>=3) {
                    five-=3;
                    twen++;
                }

                else {
                    return false;
                }
            }
           
        }

        return true;
    }