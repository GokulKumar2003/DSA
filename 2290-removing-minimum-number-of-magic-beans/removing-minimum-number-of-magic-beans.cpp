class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        long long sum = 0, rem = 0;
        for(int i=0;i<beans.size();i++){
            sum += beans[i];
        }

        sort(beans.begin(), beans.end());
        long long ans = LLONG_MAX;
        for(int i=0;i<beans.size();i++){
            sum -= beans[i];
            ans = min(ans, rem + (sum - (beans[i]*((long long)beans.size()-i-1))));
            rem += beans[i];
        }

        return ans;
    }
};