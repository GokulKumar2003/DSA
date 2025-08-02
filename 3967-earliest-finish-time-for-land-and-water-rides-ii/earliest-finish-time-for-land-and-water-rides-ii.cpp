class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        vector<vector<int>> l,w;
        for(int i=0;i<landStartTime.size();i++){
            l.push_back({landStartTime[i] + landDuration[i], landStartTime[i]});
        }

        for(int i=0;i<waterStartTime.size();i++){
            w.push_back({waterStartTime[i] + waterDuration[i], waterStartTime[i]});
        }

        sort(l.begin(), l.end());
        sort(w.begin(), w.end());
        int case1 = INT_MAX, case2 = INT_MAX;

        for(int i=0;i<w.size();i++){
            if(w[i][1] > l[0][0]){
                case1 = min(case1, w[i][0]);
            }
            else{
                case1 = min(case1, l[0][0] + w[i][0] - w[i][1]);
            }
        }

        for(int i=0;i<l.size();i++){
            if(l[i][1] > w[0][0]){
                case2 = min(case2, l[i][0]);
            }
            else{
                case2 = min(case2, w[0][0] + l[i][0] - l[i][1]);
            }
        }
            
       return min(case1, case2);
    }
};