class Solution {
public:
    long long coloredCells(int n) {
        
        
        if(n==1){
            return 1;
        }
        
        long long inc = 4;
        long long ans=1;
        for(int i=2;i<=n;i++){
            ans += inc;
            inc += 4;
        }
        
        return ans;
    }
};