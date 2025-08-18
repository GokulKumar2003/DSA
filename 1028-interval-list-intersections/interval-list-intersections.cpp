class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> ans;
        int i=0,j=0;

        while(i<firstList.size() && j<secondList.size()){
            int s1 = firstList[i][0], s2 = secondList[j][0];
            int e1 = firstList[i][1], e2 = secondList[j][1];
            if((s1 >= s2 && s1 <= e2) || (s2 >= s1 && s2 <= e1)){
                ans.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            }
            if(firstList[i][1] < secondList[j][1]){
                    i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};