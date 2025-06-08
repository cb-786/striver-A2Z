class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            vector<vector<int>> temp = matrix;
            for(int i = 0;i<matrix.size();i++) {
                for(int j=0;j<matrix[0].size();j++) {
                    if(temp[i][j] == 0) {
                        for(int k=0;k<matrix.size();k++) {
                            matrix[k][j] = 0;
                        }
    
                        for(int k=0;k<matrix[0].size();k++) {
                            matrix[i][k] = 0;
                        }
                    }
                }
            }
    
        }
    };