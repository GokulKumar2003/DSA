class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        map<int, int> m;
        if(nums.size()%k != 0){
            return false;
        }
        int maxFreq = nums.size()/k;
        for(int it:nums){
            if(++m[it] > maxFreq){
                return false;
            }
        }

        return true;
    }
};