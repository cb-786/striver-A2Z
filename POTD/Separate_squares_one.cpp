pair<double,double> ud(vector<vector<int>> &squares,double y) {
        double u = 0;
        double d = 0;
        for(const auto &ele : squares) {
            
            double j = ele[1];
            double l = ele[2];

            if(y>j && y<j+l) {
                u += (l*(j+l-y));
                d += (l*(y-j));
            }

            else if(y<=j) {
                u+=l*l;
            }

            else if(y>=j+l) d += l*l;
        }

        return {u,d};
    }



    double separateSquares(vector<vector<int>>& squares) {
         double miny = INT_MAX;
         double maxy = INT_MIN;
         for(const auto &ele : squares) {
            miny = min(miny,(double)ele[1]);
            maxy = max(maxy,(double)ele[1]+(double)ele[2]);
         }

          double eps = 1e-5;

    while (maxy - miny > eps) {
        double mid = (miny + maxy) / 2.0;
        auto curr = ud(squares, mid);

        if (curr.first > curr.second)
            miny = mid;
        else
            maxy = mid;
    }

    return (miny + maxy) / 2.0;
    }