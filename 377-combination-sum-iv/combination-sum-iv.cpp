class Solution {
public:
    int find(vector<int>& nums, int n, int target, vector<int>& dp){
        if(target == 0){
            return 1;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        dp[target] = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= target){
                dp[target] += find(nums, n, target - nums[i], dp);
            }
        }

        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<int> dp(target+1, -1);
        return find(nums, n, target, dp);
    }
};