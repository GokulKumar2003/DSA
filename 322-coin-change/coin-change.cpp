class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0){
            return 0;
        }
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i=0;i<=amount;i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int amt=1;amt<=amount;amt++){
                int pick=INT_MAX, not_pick = INT_MAX;
                not_pick = dp[i-1][amt];
                if(amt-coins[i] >= 0){
                    pick = dp[i][amt-coins[i]] + 1;
                }
                dp[i][amt] = min(pick, not_pick);
            }
        }
        
        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};