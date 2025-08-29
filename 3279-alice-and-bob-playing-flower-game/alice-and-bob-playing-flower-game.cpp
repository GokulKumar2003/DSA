class Solution {
public:
    long long flowerGame(int n, int m) {
        
        long long cnt = 0, odd = m/2 + m%2, even = m/2;
        for(int i=1;i<=n;i++){
            if(i%2 == 0){
                cnt += odd;
            }
            else{
                cnt += even;
            }
        }

        return cnt;
    }
};