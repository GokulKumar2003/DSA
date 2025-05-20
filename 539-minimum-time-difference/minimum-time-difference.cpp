class Solution {
public:
    int calculateDiff(string s, string e){

        int h1,m1,h2,m2;
        h1 = (s[0]-'0')*10 + (s[1]-'0');
        m1 = (s[3]-'0')*10 + (s[4]-'0');

        h2 = (e[0]-'0')*10 + (e[1]-'0');
        m2 = (e[3]-'0')*10 + (e[4]-'0');
        
        int diff1 = 0, diff2 = 0;
        if(h1 > h2){
            diff1 = (h1-h2-1)*60 + m1 + (60 - m2);
            diff2 = h2*60 + m2 + (24-h1-1)*60 + (60-m1);
        }
        else if(h2 > h1){
            diff1 = (h2-h1-1)*60 + m2 + (60 - m1);
            diff2 = h1*60 + m1 + (24-h2-1)*60 + (60-m2);
        }
        else{
            diff1 = abs(m2 - m1);
            diff2 = INT_MAX;
        }
        
        return min(diff1, diff2);
    }
    int findMinDifference(vector<string>& timePoints) {
        
        int minDiff = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        for(int i=0;i<timePoints.size()-1;i++){
            string startTime = timePoints[i];
            string endTime = timePoints[i+1];
            minDiff = min(minDiff, calculateDiff(startTime, endTime));
        }

        minDiff = min(minDiff, calculateDiff(timePoints[0], timePoints[timePoints.size()-1]));
        return minDiff;
    }
};