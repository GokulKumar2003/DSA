class Solution {
public:
    int solve(int l, int r, string& s, vector<vector<int>>& dp){
        if(l>=r){
            return 0;
        }
        int ans = 0;
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        if(s[l] == s[r]){
            return dp[l][r] = solve(l+1, r-1, s, dp);
        }
        return dp[l][r] = 1 + min(solve(l+1, r, s, dp), solve(l, r-1, s, dp));
    }
    int almostPalindromic(string s) {
        
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, -1));
        int ans = 0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                int len = j-i+1;
                if(len >=2 && solve(i, j, s, dp) <= 1){
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};