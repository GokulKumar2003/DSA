class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
         
        sort(nums.begin(), nums.end());
        int minNum = INT_MIN;
        int cnt = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] - k > minNum){
                cnt++;
                minNum = nums[i] - k;
            }
            else if(nums[i] + k > minNum){
                minNum++;
                cnt++;
            }
        }
        return cnt;

    }
};