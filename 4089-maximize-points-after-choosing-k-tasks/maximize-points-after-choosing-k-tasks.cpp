class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
 
        vector<vector<int>> diff;
        long long ans = 0;

        for(int i=0;i<technique1.size();i++){
            diff.push_back({technique2[i] - technique1[i], i});
        
        }

        sort(diff.begin(), diff.end());

        int i=0;
        for(i=0;i<k;i++){
            int ind = diff[i][1];
            ans += technique1[ind];
        }
        for(;i<technique1.size();i++){
            int ind = diff[i][1];
            ans += max(technique1[ind], technique2[ind]);
        }

        return ans;

    }
};