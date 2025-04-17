class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int j=1, ans = 0, prevEnd = intervals[0][1];

        while(j < intervals.size()){
            if(intervals[j][0] < prevEnd){
                ans++;
                prevEnd = min(prevEnd, intervals[j][1]);
            }
            else{
               prevEnd = intervals[j][1];
            }
            j++;
        }
        return ans;
    }
};