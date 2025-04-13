class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        if(target > sum || target < -1*sum){
            return 0;
        }
    
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2*sum+1, 0));

        dp[0][nums[0]+sum] += 1;
        dp[0][-1*nums[0]+sum] += 1;

        for(int i=1;i<n;i++){
            for(int s = -1*sum; s<=sum;s++){
                int pos=0, neg=0;
                if(s-nums[i] >= -1*sum){
                    pos = dp[i-1][s-nums[i]+sum];
                }
                if(s+nums[i] <= sum){
                    neg = dp[i-1][s+nums[i]+sum];
                }
                dp[i][s+sum] = pos + neg;
            }
        }

        return dp[n-1][target+sum];
    }
};