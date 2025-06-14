class Solution {
public:
    int find(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2, bool picked, vector<vector<vector<int>>>& dp){
        if(ind1 == nums1.size() || ind2 == nums2.size()){
            if(picked == 0){
                return -1e9;
            }
            return 0;
        }
        if(dp[ind1][ind2][picked] != -1){
            return dp[ind1][ind2][picked];
        }
        int pick = 0, not_pick1 = 0, not_pick2 = 0, not_pick3 = 0;
        not_pick1 = find(nums1, nums2, ind1 + 1, ind2 + 1, picked, dp);
        not_pick2 = find(nums1, nums2, ind1 + 1, ind2, picked, dp);
        not_pick3 = find(nums1, nums2, ind1, ind2 + 1, picked, dp);

        pick = nums1[ind1]*nums2[ind2] + find(nums1, nums2, ind1 + 1, ind2 + 1, 1, dp);

        return dp[ind1][ind2][picked] = max(pick, max(not_pick1, max(not_pick2, not_pick3)));

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<vector<int>>> dp(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(2, -1)));
        return find(nums1, nums2, 0, 0, 0, dp);
    }
};