class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        if(derived.size() == 1 && derived[0] == 1){
            return false;
        }

        // [d1, d2, d3] derived
        // [a1, a2, a3] actual
        // [d1, d2, d3] = [a1^a2, a2^a3, a1^a3]
        // a1^a2 ^ a2^a3 = a1^a3

        int xorVal = 0;
        for(int i=0;i<derived.size()-1;i++){
            xorVal ^= derived[i];
        }

        return xorVal == derived[derived.size() - 1];
    }
};