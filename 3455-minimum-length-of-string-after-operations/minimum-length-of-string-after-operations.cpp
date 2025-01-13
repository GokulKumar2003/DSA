class Solution {
public:
    int minimumLength(string s) {
        
        vector<int> left(26, 0), right(26, 0), deleteCnt(26, 0);
        
        for(int i=0;i<s.length();i++){
            right[s[i] - 'a'] += 1;
        }

        for(int i=0;i<s.length();i++){
            right[s[i] - 'a'] -= 1;
            if(left[s[i] - 'a'] && right[s[i] - 'a']){
                left[s[i] - 'a'] -= 1;
                right[s[i] - 'a'] -= 1;
            }
            left[s[i] - 'a'] += 1;
        }

        int ans = 0;
        for(int i=0;i<left.size();i++){
            ans += left[i];
        }
        return ans;
    }
};