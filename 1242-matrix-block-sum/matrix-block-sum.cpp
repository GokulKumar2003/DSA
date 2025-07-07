class Solution {
public:
    int findSum(vector<vector<int>>& mat, int r, int c, int k){
        int n = mat.size(), m = mat[0].size();
        int sr = max(0, r-k), er = min(n-1, r+k);
        int sc = max(0, c-k), ec = min(m-1, c+k);

        int sum = 0;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                sum += mat[i][j];
            }
        }
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> ans;

        for(int i=0;i<mat.size();i++){
            vector<int> temp;
            for(int j=0;j<mat[0].size();j++){
                int prod = findSum(mat, i, j, k);
                temp.push_back(prod);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};