class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int i=0,j=0, minSubSeqCnt = 1;
        while(j<nums.size()){
            if(nums[j] - nums[i] > k){
                minSubSeqCnt++;
                i=j;
            }
            j++;
        }

        return minSubSeqCnt;
    }
};