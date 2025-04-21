class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int num = 0;
        int maxi = 0, mini = 0;

        for(int it : differences){
            num += it;
            maxi = max(maxi, num);
            mini = min(mini, num);
            if (maxi - mini > upper - lower) {
                return 0;
            }
        }
       
        return (upper - maxi) - (lower - mini) + 1;
    }
};