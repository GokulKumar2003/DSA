class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size()/2], ans = 0;
        for(int it:nums){
            ans += abs(it - mid);
        }

        return ans;
    }
};