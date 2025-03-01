class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        vector<int> ans = nums;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i] == ans[i+1]){
                ans[i] *= 2;
                ans[i+1] = 0;
            }
        }

        int l=0,r=0;
        while(r < ans.size()){
            if(ans[r] != 0){
                ans[l] = ans[r];
                l++;
                r++;
            }
            else{
                r++;
            }
        }

        while(l<ans.size()){
            ans[l] = 0;
            l++;
        }
        return ans;
    }
};