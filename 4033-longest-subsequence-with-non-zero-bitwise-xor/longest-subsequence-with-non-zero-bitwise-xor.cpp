class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int zerocnt = 0, x = 0;
        for(int it:nums){
            if(it == 0){
                zerocnt++;
            }
            x = x ^ it;
        }

        if(zerocnt == nums.size()){
            return 0;
        }
        if(x){
            return nums.size();
        }
        return nums.size()-1;
    }
};