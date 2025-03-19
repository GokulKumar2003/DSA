class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                if(nums.size() - i < 3){
                    return -1;
                }
                ans++;
                nums[i] = 1;
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
            }
        }
        
        return ans;
    }
};