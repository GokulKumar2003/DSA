class Solution {
public:
    bool isPossibleToPick(vector<int>& freq, string word){
        vector<int> f(26, 0);
        for(char c:word){
            f[c-'a']++;
        }

        for(int i=0;i<26;i++){
            if(f[i] && f[i] > freq[i]){
                return false;
            }
        }
        return true;
    }

    void updateFreqArr(vector<int>& freq, string word){
        for(char c : word){
            freq[c-'a']--;
        }
    }

    int getScore(string word, vector<int>& score){
        
        int s = 0;
        for(char c : word){
            s += score[c-'a'];
        }

        return s;
    }
    int find(vector<string>& words, vector<int> freq, vector<int>& score, int ind){
        if(ind == words.size()){
            return 0;
        }

        int pick = 0, not_pick = 0;
        not_pick = find(words, freq, score, ind+1);
        if(isPossibleToPick(freq, words[ind])){
            updateFreqArr(freq, words[ind]);
            int s = getScore(words[ind], score);
            pick = s + find(words, freq, score, ind+1);
        }

        return max(pick, not_pick);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int> freq(26, 0);
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        return find(words, freq, score, 0);
    }
};