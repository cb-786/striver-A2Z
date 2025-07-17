bool searchMatrix(vector<vector<int>>& mat, int target) {
        int e = mat.size()*mat[0].size() -1;
        int s = 0;

        int mid = s + (e-s)/2;

        while(s<=e) {
            mid = s + (e-s)/2;
            int idx = mid/(int)mat[0].size();
            int sec = mid%(int)mat[0].size();
            if(mat[idx][sec] == target) return 1;

            else if (mat[idx][sec] > target) {
                e = mid-1;
            }

            else {
                s=mid+1;
            }
        }

        return 0;

        
    }