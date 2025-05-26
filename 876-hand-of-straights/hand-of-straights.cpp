class Solution {
public:
    void insertInAGrp(vector<vector<int>>& grps, int num, int grpSize){

        int flag = 0;
        for(int i=0;i<grps.size();i++){
            if(grps[i].size() < grpSize && grps[i][grps[i].size()-1] == num - 1){
                grps[i].push_back(num);
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            grps.push_back({num});
        }
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        vector<vector<int>> grps; /* last_ele, cnt*/
        sort(hand.begin(), hand.end());
        for(int it:hand){
            insertInAGrp(grps, it, groupSize);
        }

        for(int i=0;i<grps.size();i++){
            for(int it:grps[i]){
                cout << it << " ";
            }
            cout << endl;
            if(grps[i].size() != groupSize){
                return false;
            }
        }

        return true;
    }
};