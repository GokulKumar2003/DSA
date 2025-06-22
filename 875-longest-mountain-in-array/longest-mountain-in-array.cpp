class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        vector<int> inc(arr.size(), 0), dec(arr.size(), 0);

        for(int i=1;i<arr.size();i++){
            if(arr[i] > arr[i-1]){
                inc[i] = inc[i-1] + 1;
            }
        }

        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i] > arr[i+1]){
                dec[i] = dec[i+1] + 1;
            }
        }
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(inc[i] && dec[i]){
                ans = max(ans, inc[i] + dec[i] + 1);
            }
        }

        return ans;
    }
};