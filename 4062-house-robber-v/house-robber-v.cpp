class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        
        vector<long long> dp(nums.size()+1, 0);
        dp[0] = nums[0];

        for(int i=1;i<nums.size();i++){
            long long pick = 0, not_pick = 0;
            not_pick = dp[i-1];
            if(colors[i-1] != colors[i]){
                pick = dp[i-1] + nums[i];
            }
            else{
                if(i>1){
                    pick = dp[i-2] + nums[i];
                }
                else{
                    pick = nums[i];
                }
            }

            dp[i] = max(pick,not_pick);
        }

        return dp[nums.size()-1];
    }
};