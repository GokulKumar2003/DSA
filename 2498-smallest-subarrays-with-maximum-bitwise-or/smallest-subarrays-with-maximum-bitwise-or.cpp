class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        vector<int> pos(31, -1);
        vector<int> ans(nums.size());

        for(int i=nums.size()-1;i>=0;i--){
            int ind = i;
            for(int b=0;b<31;b++){
                if(!(nums[i] & (1 << b))){
                    if(pos[b] != -1){
                        ind = max(ind, pos[b]);
                    }
                }
                else{
                    pos[b] = i;
                }

            }
            ans[i] = ind - i + 1;
        }

        return ans;
    }
};