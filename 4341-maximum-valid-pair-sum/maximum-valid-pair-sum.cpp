class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        
        int maxi = nums[nums.size()-1];
        vector<int> temp = nums;
        for(int i=nums.size()-2;i>=0;i--){
            maxi = max(nums[i], maxi);
            temp[i] = maxi;
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(i+k < nums.size()){
                ans = max(ans, nums[i]+temp[i+k]);
            }
        }

        return ans;
    }
};