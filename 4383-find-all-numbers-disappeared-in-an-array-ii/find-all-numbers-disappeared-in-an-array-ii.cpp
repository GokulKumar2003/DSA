class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int i=0;
        while(i<nums.size()){
            if(nums[i] == lower){
                lower++;
                i++;
                continue;
            }
            if(nums[i] == upper){
                upper--;
                i++;
                continue;
            }
            if(nums[i] > lower && nums[i] < upper){
                ans.push_back({lower, nums[i]-1});
                lower = nums[i] + 1;
            }
            i++;
        }
        if(lower<=upper){
            ans.push_back({lower, upper});
        }
        return ans;
    }
};