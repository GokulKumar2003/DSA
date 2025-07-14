class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int ans = 0;
        vector<pair<int, int>> a;
        for(int i=0;i<plantTime.size();i++){
            a.push_back({plantTime[i], growTime[i]});
        }
        sort(a.begin(), a.end(), comp);
        vector<int> time;
        time.push_back(a[0].first - 1);
        for(int i=1;i<a.size();i++){
            time.push_back(time[i-1] + a[i].first);
        }
        
        for(int i=0;i<a.size();i++){
            ans = max(ans, time[i] + a[i].second + 1);
        }
        return ans;
    }
};