class Solution {
public:
    int minimumLength(string s) {
        
        vector<int> left(26, 0), right(26, 0), deleteCnt(26, 0);
        int minLength = s.length();

        for(int i=0;i<s.length();i++){
            right[s[i] - 'a'] += 1;
        }

        for(int i=0;i<s.length();i++){
            right[s[i] - 'a'] -= 1;
            if(left[s[i] - 'a'] > 0 && right[s[i] - 'a'] > 0){
                left[s[i] - 'a'] -= 1;
                right[s[i] - 'a'] -= 1;
                minLength -= 2;
            }
            left[s[i] - 'a'] += 1;
        }

        return minLength;
    }
};