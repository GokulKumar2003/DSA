class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        
        if((tomatoSlices - 2*cheeseSlices)%2 || (tomatoSlices - 2*cheeseSlices) < 0){
            return {};
        }

        int x = (tomatoSlices - 2*cheeseSlices)/2;
        int y = cheeseSlices - x;
        if(y < 0){
            return {};
        }
        return {x, y};
    }
};