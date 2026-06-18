double angleClock(int hour, int minutes) {
        
        double hd = ((double)minutes/60)*30;

        double md = ((double)minutes/60)*360;

        hd+=(hour%12)*30;

        return min(360-(hd-md),min(abs(hd-md),min(abs(360-(md-hd)),abs(md-hd))));
        
        

    }