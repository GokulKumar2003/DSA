class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> prefMax(nums.size()), suffMin(nums.size());
        prefMax[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefMax[i] = max(nums[i], prefMax[i-1]);
        }

        suffMin[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffMin[i] = min(nums[i], suffMin[i+1]);
        }

        for(int i=0;i<nums.size();i++){
            if(prefMax[i] - suffMin[i] <= k){
                return i;
            }
        }

        return -1;
    }
};