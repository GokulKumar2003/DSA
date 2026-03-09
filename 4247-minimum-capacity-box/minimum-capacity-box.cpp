class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int mini = INT_MAX, minInd = -1;

        for(int i=0;i<capacity.size();i++){
            if(capacity[i] >= itemSize){
                if(capacity[i] < mini){
                    mini = capacity[i];
                    minInd = i;
                }
            }
        }

        return minInd;
    }
};