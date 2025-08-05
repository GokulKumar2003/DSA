class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int cnt = 0, i, j;

        for(i=0;i<fruits.size();i++){
            for(j=0;j<baskets.size();j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j] = 0;
                    break;
                }
            }
            if(j == baskets.size()){
                cnt++;
            }
        }
        
        return cnt;
    }
};