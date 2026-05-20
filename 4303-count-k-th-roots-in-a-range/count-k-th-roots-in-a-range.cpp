class Solution {
public:
    
    int find(long long n, int k){
        long long l = 0, r = n, ans=0;

        while(l <= r){
            long long mid = l + (r- l)/2;
            cout << l << " " << r << endl;
            if(pow(mid, k) <= n){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
    int countKthRoots(int l, int r, int k) {
        
        int cnt1 = find(r, k);
        int cnt2 = find(l-1, k);

        int ans  = cnt1 - cnt2;
        if(l == 0){
            ans++;
        }
        return ans;
    }
};