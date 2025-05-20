class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int minFlips = s.length();
        int one = 0, zero = 0;

        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                one++;
            }
            else{
                zero++;
            }
        }

        minFlips = min(one, zero);
        int prefZero = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                one--;
            }
            else{
                prefZero++;
            }

            minFlips = min(minFlips, (int)((i+1-prefZero) + (s.length() - i -1 - one)));
        }

        return minFlips;
    }
};