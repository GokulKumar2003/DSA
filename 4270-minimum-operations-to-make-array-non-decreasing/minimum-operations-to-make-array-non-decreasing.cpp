class Solution {
public:
    long long minOperations(vector<int>& nums) {
        
        long long ans = 0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] < nums[i-1]){
                ans += (nums[i-1] - nums[i]);
            }
        }

        return ans;
    }
};