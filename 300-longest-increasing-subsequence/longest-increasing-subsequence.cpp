class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), longestIncSeqLength = 1;
        vector<int> dp(n, 1);

        for(int ind = 1; ind < n; ind++){
            int maxi = 1;
            for(int prev = 0; prev < ind; prev++){
                if(nums[ind] > nums[prev]){
                    maxi = max(maxi, 1 + dp[prev]);
                }
                dp[ind] = maxi;
                longestIncSeqLength = max(longestIncSeqLength, dp[ind]);
            }
        }

        return longestIncSeqLength;
    }
};