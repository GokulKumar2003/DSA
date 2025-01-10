class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> universalStrings;
        
        vector<int> maxWords2Freq(26, 0);
        for(int i=0;i<words2.size();i++){
            vector<int> words2Freq(26, 0);
            for(char c:words2[i]){
                words2Freq[c-'a']++;
            }
            for(int j=0;j<words2Freq.size();j++){
                maxWords2Freq[j] = max(maxWords2Freq[j], words2Freq[j]);
            }
        }

        for(int it:maxWords2Freq){
            cout << it << " ";
        }
        cout << endl;
        for(int i=0;i<words1.size();i++){
            vector<int> word1Freq(26, 0);
            for(char c:words1[i]){
                word1Freq[c-'a']++;
            }
            bool flag = true;
            for(int j=0;j<word1Freq.size();j++){
                if(word1Freq[j] < maxWords2Freq[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                universalStrings.push_back(words1[i]);
            }
        }
        return universalStrings;
    }
};