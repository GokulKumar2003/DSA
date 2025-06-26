class Solution {
public:
    int find(string& s, int ind, int p, int k, int num, vector<vector<int>>& dp){
        if(ind < 0){
            return 0;
        }
        
        if(dp[ind][p] != -1){
            return dp[ind][p];
        }

        int pick = 0, not_pick = 0;
        if(s[ind] == '1'){
            if(pow(2, p) + num <= k){
                pick = 1 + find(s, ind-1, p+1, k, num + pow(2, p), dp);
            } 
        }
        else{
            pick = 1 + find(s, ind-1, p+1, k, num, dp);
        }

        not_pick = find(s, ind-1, p, k, num, dp);

        return dp[ind][p] = max(pick , not_pick);
    }
    int longestSubsequence(string s, int k) {
        
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return find(s, s.length()-1, 0, k, 0, dp);
    }
};