class Solution {
public:
    bool canPartitionGrid(const vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return false;

        int R = grid.size();
        int C = grid[0].size();
        
        vector<long long> rowSums(R, 0);
        vector<long long> colSums(C, 0);
        long long totalSum = 0;
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int val = grid[i][j];
                rowSums[i] += val;
                colSums[j] += val;
                totalSum += val;
            }
        }
        
        if (totalSum % 2 != 0) {
            return false;
        }
        
        long long target = totalSum / 2;
        
        long long currentSum = 0;
        for (int i = 0; i < R - 1; ++i) { 
            currentSum += rowSums[i];
            if (currentSum == target) return true;
            if (currentSum > target) break; 
        }
        
        currentSum = 0;
        for (int j = 0; j < C - 1; ++j) { 
            currentSum += colSums[j];
            if (currentSum == target) return true;
            if (currentSum > target) break; 
        }
        
        return false;
    }
};