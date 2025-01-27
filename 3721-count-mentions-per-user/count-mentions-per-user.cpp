class Solution {
public:
    static bool comp(vector<string>& a, vector<string>& b){
        
        if(stoi(a[1]) < stoi(b[1])){
            return true;
        }
        else if(stoi(a[1]) == stoi(b[1])){
            return a[0] == "OFFLINE";
        }
        return false;
    }
    void returnOnline(int currTime, vector<int>& lastActiveTime){
        
        for(int i=0;i<lastActiveTime.size();i++){
            if(currTime - abs(lastActiveTime[i]) >= 60){
                lastActiveTime[i] = currTime;
            }
        }
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        sort(events.begin(), events.end(), comp);
        
        vector<int> lastActiveTime(numberOfUsers, 0);
        vector<int> mentions(numberOfUsers, 0);
        
        for(auto it:events){
            cout << it[0] << " " << it[1] << " " << it[2] << endl;
        }
        cout << endl;
        for(auto it:events){
            
            returnOnline(stoi(it[1]), lastActiveTime);
            if(it[0] == "OFFLINE"){
                int id = stoi(it[2]);
                lastActiveTime[id] = -1*stoi(it[1]);
            }
            else{
                
                if(it[2] == "ALL"){
                    for(int i=0;i<mentions.size();i++){
                        mentions[i] += 1;
                    }
                }
                else if(it[2] == "HERE"){
                    for(int i=0;i<mentions.size();i++){
                        if(lastActiveTime[i] >= 0){
                            mentions[i] += 1;
                        }
                    }
                }
                else{
                    size_t pos = 0;
                    while(pos < it[2].length()){
                        int id=0;
                        if(it[2].substr(pos, 2) == "id"){
                            pos += 2;
                            
                            while(pos < it[2].length() && it[2][pos] >= '0' && it[2][pos] <= '9'){
                                id = id*10 + (it[2][pos]-'0');
                                pos++;
                            }
                            mentions[id] += 1;
                            id=0;
                        }
                        else{
                            pos += 1;
                        }
                    }
                }
                
            }
        }
        return mentions;
        
    }
};