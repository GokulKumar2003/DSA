class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        vector<int> ans;
        vector<int> freq(A.size()+1, 0);
        int prefCnt = 0;

        for(int i=0;i<A.size();i++){
            freq[A[i]] += 1;
            freq[B[i]] += 1;
            if(A[i] != B[i]){
                if(freq[A[i]] == 2){
                    prefCnt += 1;
                }
                if(freq[B[i]] == 2){
                    prefCnt += 1;
                }
            }
            else{
                if(freq[A[i]] == 2){
                    prefCnt += 1;
                }
            }
            
            ans.push_back(prefCnt);
        }

        return ans;
    }
};