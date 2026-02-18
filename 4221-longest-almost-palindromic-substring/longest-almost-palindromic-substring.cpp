class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isAlmostPalindrome(string& s, int l, int r){
        while(l<=r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                if(isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    int almostPalindromic(string s) {
        
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, -1));
        int ans = 0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                int len = j-i+1;
                if(len > ans && len >=2 && isAlmostPalindrome(s, i, j)){
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};