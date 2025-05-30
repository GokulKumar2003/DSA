class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;

        int i=0,j=0;
        while(j<nums.size()){
            
            if(dq.size() && dq.front() == j - k){
                dq.pop_front();
            }

            while(dq.size() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
    
            if(j>=k-1){
                ans.push_back(nums[dq.front()]);
            }
            j++;
        }

        return ans;
    }
};