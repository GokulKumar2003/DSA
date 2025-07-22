class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int maxScore = 0, i = 0, j = 0, score = 0;
        map<int, int> m;
        while(j < nums.size()){
            score += nums[j];
            m[nums[j]]++;

            while(m[nums[j]] == 2){
                score -= nums[i];
                m[nums[i]]--;
                if(m[nums[i]] == 0){
                    m.erase(nums[i]);
                }
                i++;
            }
            maxScore = max(maxScore, score);
            j++;
        }

        return maxScore;
    }
};