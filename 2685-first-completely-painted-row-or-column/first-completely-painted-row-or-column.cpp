class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        map<int, pair<int, int>> pos; // val -> {row, col}
        vector<int> rows(mat.size(), 0); // tracks the no of cells in that row that re painted
        vector<int> cols(mat[0].size(), 0); // tracks no of cells in that col are painted

        //fill the pos map
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                pos[mat[i][j]] = {i,j};
            }
        }

        // painting process
        for(int i=0;i<arr.size();i++){
            int r = pos[arr[i]].first;
            int c = pos[arr[i]].second;

            rows[r]++;
            cols[c]++;
            if(rows[r] == mat[0].size() || cols[c] == mat.size()){
                return i;
            }
        }

        return 0;
    }
};