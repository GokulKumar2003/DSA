class Solution {
public:
    string maximumXor(string s, string t) {
        int zero = 0, one = 0;
        for(char c:t){
            if(c == '1'){
                one++;
            }
            else{
                zero++;
            }
        }

        string ans="";
        for(char c:s){
            if(c == '1'){
                if(zero){
                    ans += '1';
                    zero--;
                }
                else{
                    ans += '0';
                    one--;
                }
            }
            else{
                if(one){
                    ans += '1';
                    one--;
                }
                else{
                    ans += '0';
                    zero--;
                }
            }
        }

        return ans;
    }
};