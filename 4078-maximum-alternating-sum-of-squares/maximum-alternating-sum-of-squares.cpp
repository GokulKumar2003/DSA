class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end(), greater<int>());
        int even = nums.size()/2;
        if(nums.size()%2 != 0){
            even++;
        }
        long long ans = 0;
        for(int i=0;i<even;i++){
            ans += nums[i]*nums[i];
        }
        for(int i=even;i<nums.size();i++){
            ans -= nums[i]*nums[i];
        }

        return ans;
    }
};