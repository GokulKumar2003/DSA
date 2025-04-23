class Solution {
public:
    int findNoOfTeams(vector<int>& rating){

        int noOfTeams = 0;
        for(int i=1;i<rating.size()-1;i++){
            int min_cnt = 0, max_cnt = 0;
            for(int j=i-1;j>=0;j--){
                if(rating[i] > rating[j]){
                    min_cnt += 1;
                }
            }
            for(int j=i+1;j<rating.size();j++){
                if(rating[i] < rating[j]){
                    max_cnt += 1;
                }
            }
            noOfTeams += min_cnt*max_cnt;
        }
        return noOfTeams;
    }
    int numTeams(vector<int>& rating) {
        
        /* this could be either longest increasing 
        subsequnce or longest decreasing subsequnce of length 3
        First lets find the possiblities for LIS and then for LDS*/
        /* Since it is a size of 3, for every element we could find the no of 
        min values before it and no of elements which are greater after it */
        int case1 = findNoOfTeams(rating);
        reverse(rating.begin(), rating.end());
        int case2 = findNoOfTeams(rating);

        return case1 + case2;
    }
};