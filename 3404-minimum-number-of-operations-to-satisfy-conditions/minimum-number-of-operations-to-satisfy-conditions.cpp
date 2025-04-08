class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(10, vector<int>(n, 0));
        vector<map<int, int>> mp;

        for(int col=0;col<n;col++){
            map<int, int> freq;
            for(int row =0;row<m;row++){
                freq[grid[row][col]]++;
            }
            mp.push_back(freq);
        }

        for(int r=0;r<10;r++){
            dp[r][0] = m - mp[0][r];
        }
        
        for(int c=1;c<n;c++){
            for(int r=0;r<10;r++){
                int mini = INT_MAX;
                for(int pcr=0;pcr<10;pcr++){
                    if(pcr == r){
                        continue;
                    }
                    mini = min(mini, dp[pcr][c-1]);
                }
                dp[r][c] = m - mp[c][r] + mini;
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<10;i++){
            ans = min(ans, dp[i][n-1]);
        }
        for(auto it:dp){
            for(int it1:it){
                cout << it1 << " ";
            }
            cout << endl;
        }
        return ans;
    }
};