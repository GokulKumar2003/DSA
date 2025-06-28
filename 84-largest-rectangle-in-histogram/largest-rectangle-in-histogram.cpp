class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int mod=1000000007;

        int n=nums.size(),ans=0;

        stack<int> st1,st2;

        vector<int> pre_smaller(n),next_smaller(n);

        for(int i=0;i<n;i++){
            next_smaller[i] = n-i-1;
            pre_smaller[i]=i;
        }

        for(int i=0;i<n;i++){

            while(st1.size() && nums[i]<nums[st1.top()]){
                next_smaller[st1.top()] = i-st1.top()-1;
                st1.pop();
            }
            st1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(st2.size() && nums[i]<nums[st2.top()]){
                pre_smaller[st2.top()] = st2.top()-i-1;
                st2.pop();
            }
            st2.push(i);
        }

        for(int i=0;i<n;i++){
           // ans = (ans + nums[i]*(long long)(next_smaller[i]+1)*(long long)(pre_smaller[i]+1))%mod;

          ans = max(ans,nums[i]*(pre_smaller[i]+next_smaller[i]+1));
        }

        return ans;
    }
};