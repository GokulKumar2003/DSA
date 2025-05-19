class Solution {
public:
    bool isPossible(vector<int>& arr, int val, int n){
        int storesCnt = 0;

        for(int i=0;i<arr.size();i++){
            storesCnt += (ceil)((double)arr[i]/val);
        }

        return storesCnt <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int l = 1, h = *max_element(quantities.begin(), quantities.end()), mid, ans;

        while(l <= h){
            mid = l + (h - l)/2;
            if(isPossible(quantities, mid, n)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};