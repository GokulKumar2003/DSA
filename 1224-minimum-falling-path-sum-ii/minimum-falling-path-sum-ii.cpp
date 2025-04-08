class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dp = grid;

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini = INT_MAX;
                for(int k=0;k<n;k++){
                    if(j!=k){
                        mini = min(dp[i-1][k], mini);
                    }
                }
                dp[i][j] = mini + grid[i][j];
            }
        }

        for(auto it:dp){
            for(int it1:it){
                cout << it1 << " ";
            }
            cout << endl;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};