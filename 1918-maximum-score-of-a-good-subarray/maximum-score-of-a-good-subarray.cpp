class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> next_smaller(n, 0), prev_smaller(n, 0);
        stack<int> st;

        for(int i=0;i<nums.size();i++){
            prev_smaller[i] = i;
            next_smaller[i] = n - i - 1;
        }

        for(int i=0;i<n;i++){
            while(st.size() && nums[i] < nums[st.top()]){
                next_smaller[st.top()] = i - st.top() - 1;
                st.pop();
            }
            st.push(i);
        }

        while(st.size()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(st.size() && nums[i] < nums[st.top()]){
                prev_smaller[st.top()] = st.top() - i - 1;
                st.pop();
            }
            st.push(i);
        }

        // for(int it:prev_smaller){
        //     cout << it << " ";
        // }
        // cout << endl;
        // for(int it : next_smaller){
        //     cout << it << " ";
        // }
        // cout << endl;

        int ans = 0;
        for(int i=0;i<n;i++){
            if(i - prev_smaller[i] <= k && i + next_smaller[i] >= k){
                cout << i << " " << nums[i]*(next_smaller[i] + prev_smaller[i] + 1) << endl;
                ans = max(ans, nums[i]*(next_smaller[i] + prev_smaller[i] + 1));
            }
        }

        return ans;

    }
};