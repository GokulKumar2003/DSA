class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        
        int op1=0, op2 = 0;

        /* making elem at even idx greater than its adj */
        vector<int> temp = nums;
        for(int i=0;i<nums.size();i+=2){
            if(i!=0 && temp[i-1] >= temp[i]) {
                op1 += abs(temp[i] - temp[i-1])+1;
                temp[i-1] = temp[i]-1;
            }
            if(i<temp.size() -1 && temp[i+1] >= temp[i]){
                op1 += abs(temp[i] - temp[i+1])+1;
                temp[i+1] = temp[i]-1;
            }
        }

        /* making elem at odd idx greater than its adj */
        temp = nums;
        for(int i=1;i<nums.size();i+=2){
           if(i!=0 && temp[i-1] >= temp[i]) {
                op2 += abs(temp[i] - temp[i-1])+1;
                temp[i-1] = temp[i]-1;
            }
            if(i<temp.size() -1 && temp[i+1] >= temp[i]){
                op2 += abs(temp[i] - temp[i+1])+1;
                temp[i+1] = temp[i]-1;
            }
        }

        return min(op1, op2);
    }
};