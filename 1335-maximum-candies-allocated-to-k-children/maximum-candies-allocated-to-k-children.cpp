class Solution {
public:
    bool canDistribute(vector<int>& candies, int count, long long k){

        long long allocatedChildrenCnt = 0;
        for(int it:candies){
            allocatedChildrenCnt += it/count;
        }

        return allocatedChildrenCnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int left = 1, right = 0, mid, ans = 0;
        for(int it:candies){
            right = max(right, it);
        }

        while(left <= right){
            mid = left + (right - left)/2;

            if(canDistribute(candies, mid, k)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;
    }
};