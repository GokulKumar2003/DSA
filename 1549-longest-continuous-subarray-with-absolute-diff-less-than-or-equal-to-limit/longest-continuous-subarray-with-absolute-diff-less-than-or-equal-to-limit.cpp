class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int maxLen = 0;
        deque<int> maxq, minq;
    
        for(int i=0,j=0;j<nums.size();j++){
            while(maxq.size() && nums[maxq.back()] < nums[j]){
                maxq.pop_back();
            }
            maxq.push_back(j);

            while(minq.size() && nums[minq.back()] > nums[j]){
                minq.pop_back();
            }
            minq.push_back(j);

            while(maxq.size() && minq.size() && nums[maxq.front()] - nums[minq.front()] > limit){
                if(i==maxq.front()){
                    maxq.pop_front();
                }
                if(i == minq.front()){
                    minq.pop_front();
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }

        return maxLen;
    }
};