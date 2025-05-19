class Solution {
public:
    bool isPossible(vector<int>& ranks, long long mid, int cars){
        
        long long cnt = 0;
        for(int i=0;i<ranks.size();i++){
            long long x = mid/ranks[i];
            cnt += sqrt((mid/ranks[i]));
        }

        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        
        long long minTime = 1, maxTime = LLONG_MAX, mid, ans = 0;

        while(minTime <= maxTime){
            mid = minTime + (maxTime - minTime)/2;

            if(isPossible(ranks, mid, cars)){
                ans = mid;
                maxTime = mid - 1;
            }
            else{
                minTime = mid + 1;
            }
        }

        return ans;
    }
};