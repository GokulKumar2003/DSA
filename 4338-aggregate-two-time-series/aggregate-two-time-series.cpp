class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        
        int i=0, j=0;
        vector<vector<int>> ans;
        while(i<series1.size() && j<series2.size()){

            int val = series1[i][1] + series2[j][1];
            
            if(series1[i][0] < series2[j][0]){
                ans.push_back({series1[i][0], val});
                i++;
            }
            else if(series1[i][0] > series2[j][0]){
                ans.push_back({series2[j][0], val});
                j++;
            }
            else{
                ans.push_back({series2[j][0], val});
                i++;
                j++;
            }
        }

        while(i<series1.size()){
            ans.push_back(series1[i]);
            i++;
        }
        while(j<series2.size()){
            ans.push_back(series2[j]);
            j++;
        }

        return ans;
    }
};