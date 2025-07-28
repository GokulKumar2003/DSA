class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    bool isAllVowelPresent(vector<int>& arr){

        return (arr['a'-'a'] && arr['e'-'a'] && arr['i'-'a'] && arr['o'-'a'] && arr['u'-'a']);
    }
    long long countOfSubstrings(string word, int k) {
        
        long long ans = 0, consonantCnt = 0;
        vector<int> arr(26, 0);
        vector<int> nextConsonant(word.length());
        int nextConsonantInd = word.length();
        for(int i=word.length()-1;i>=0;i--){
            nextConsonant[i] = nextConsonantInd;
            if(!isVowel(word[i])){
                nextConsonantInd = i;
            }
        }

        int i=0,j=0;
        while(j<word.length()){

            if(isVowel(word[j])){
                arr[word[j] - 'a']++;
            }
            else{
                consonantCnt++;
            }

            while(consonantCnt > k){
                if(isVowel(word[i])){
                    arr[word[i] - 'a']--;
                }
                else{
                    consonantCnt--;
                }
                i++;
            }

            while(i<word.length() && isAllVowelPresent(arr) && consonantCnt == k){
                ans += nextConsonant[j] - j;
                if(isVowel(word[i])){
                    arr[word[i]-'a']--;
                }
                else{
                    consonantCnt--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};