class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int, int> numToFreq;
        map<int, set<int>> freqToNum;

        for(int i=0;i<nums.size();i++){
            int prevFreq = 0, currFreq;
            if(numToFreq.find(nums[i]) != numToFreq.end()){
                prevFreq = numToFreq[nums[i]];
                freqToNum[prevFreq].erase(nums[i]);
            }
            currFreq = prevFreq + 1;
            freqToNum[currFreq].insert(nums[i]);
            numToFreq[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(freqToNum[numToFreq[nums[i]]].size() == 1){
                return nums[i];
            }
        }
        return -1;
    }
};