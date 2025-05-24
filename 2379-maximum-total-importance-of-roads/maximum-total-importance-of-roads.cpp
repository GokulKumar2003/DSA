class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> freq(n, 0);
        for(int i=0;i<roads.size();i++){
            freq[roads[i][0]]++;
            freq[roads[i][1]]++;
        }

        sort(freq.begin(), freq.end());
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += (long long)(i+1)*(long long)freq[i];
        }

        return ans;
    }
};