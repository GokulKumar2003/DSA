class Solution {
public:
    int find_next_ind(vector<vector<int>>& events, int end_time){
        
        int l = 0, r = events.size()-1, mid, ans = events.size();

        while(l<=r){
            mid = l + (r-l)/2;

            if(events[mid][0] > end_time){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
    int find(vector<vector<int>>& events, int k, int ind, vector<vector<int>>& dp){
        if(k == 0 || ind == events.size()){
            return 0;
        }

        if(dp[ind][k] != -1){
            return dp[ind][k];
        }

        int pick = 0, not_pick = 0;
        int next_ind = find_next_ind(events, events[ind][1]);
        pick = events[ind][2] + find(events, k-1, next_ind, dp);

        not_pick = find(events, k, ind+1, dp);

        return dp[ind][k] = max(pick, not_pick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k+1, -1));
        return find(events, k, 0, dp);
    }
};