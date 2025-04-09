class Solution {
public:
    int find(vector<vector<int>>& grid, int n, int r1, int c1, int c2, vector<vector<vector<int>>>& dp){

        int r2 = r1 + c1 - c2;
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        if(dp[r1][c1][c2] != -1){
            return dp[r1][c1][c2];
        }

        if(r1 == n-1 && c1 == n-1){
            return grid[r1][c1];
        }

        
        int currentPick = grid[r1][c1];
        if(c1 != c2){
            currentPick += grid[r2][c2];
        }

        int rightRight = 0, rightDown = 0, downRight = 0, downDown = 0;

        rightRight = find(grid, n, r1, c1 + 1, c2 + 1, dp);
        rightDown = find(grid, n, r1, c1 + 1, c2, dp);
        downRight = find(grid, n, r1 + 1, c1, c2 + 1, dp);
        downDown = find(grid, n ,r1 + 1, c1, c2, dp);

        currentPick += max(rightRight, max(rightDown, max(downRight, downDown)));
        return dp[r1][c1][c2] = currentPick;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, find(grid, n, 0, 0, 0, dp));
    }
};