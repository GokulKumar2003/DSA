class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.length() < k){
            return false;
        }
        vector<int> freq(26, 0);
        for(int i=0;i<s.length();i++){
            freq[s[i] - 'a']++;
        }

        int oddCnt = 0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]%2 == 1){
                oddCnt++;
            }
        }

        if(oddCnt > k){
            return false;
        }
        return true;
    }
};