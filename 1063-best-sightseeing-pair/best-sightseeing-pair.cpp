class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int prev_maxi = values[0], ans = 0;

        for(int i=1;i<values.size();i++){
            ans = max(ans, prev_maxi + values[i] - i);
            prev_maxi = max(prev_maxi, values[i] + i);
        }

        return ans;
    }
};