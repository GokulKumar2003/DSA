class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        map<int, int> m;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i] + k) != m.end()){
                ans += m[nums[i]+k];
            }
            if(m.find(nums[i] - k) != m.end()){
                ans += m[nums[i] - k];
            }
            m[nums[i]]++;
        }

        return ans;
    }
};