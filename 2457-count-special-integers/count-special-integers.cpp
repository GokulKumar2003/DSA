class Solution {
public:
    int find(string& n, int ind, bool tight, bool isTrailingZero, int mask){

        if(ind == n.length()){
            return isTrailingZero ? 0 : 1;
        }
        int res = 0;
        int limit = tight ? (n[ind] - '0') : 9;

        for(int d = 0;d <= limit; d++){
            /* digit is already taken */
            if(!isTrailingZero && ((1 << d) & mask)){
                continue;
            }

            bool newTight = tight && (d == limit);
            bool newIsTrailingZero = isTrailingZero && (d == 0);
            int newMask = newIsTrailingZero ? mask : (mask | (1 << d));

            res += find(n, ind+1, newTight, newIsTrailingZero, newMask);
        }

        return res;
    }
    int countSpecialNumbers(int n) {
        
        string num = to_string(n);
        return find(num, 0, 1, 1, 0);
    }
};