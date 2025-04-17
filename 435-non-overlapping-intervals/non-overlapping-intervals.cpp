class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int i=0,j=1, ans = 0;

        while(j < intervals.size()){
            if(intervals[j][0] < intervals[i][1]){
                ans++;
                if(intervals[i][1] < intervals[j][1]){
                    j++;
                }
                else{
                    i=j;
                    j++;   
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return ans;
    }
};