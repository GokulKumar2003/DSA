class Solution {
public:
    int minLights(vector<int>& lights) {
        
        int lastLight = -1;
        for(int i=0;i<lights.size();i++){
            if(lights[i] == 0){
                if(lastLight != -1){
                    if(lastLight + lights[lastLight] >= i){
                        lights[i] = -1;
                    }
                }   
            }
            else if(lights[i] > 0){
                if(lastLight == -1){
                    lastLight = i;
                }
                else if((lights[lastLight] - abs(i - lastLight) < lights[i])){
                    lastLight = i;
                } 
            }
        }
        lastLight = -1;
        for(int i=lights.size()-1;i>=0;i--){
            if(lights[i] == 0){
                if(lastLight != -1){
                    if(i >= lastLight - lights[lastLight]){
                        lights[i] = -1;
                    }
                }
            }
            else if(lights[i] > 0){
                if(lastLight == -1){
                    lastLight = i;
                }
                else if((lights[lastLight] - abs(lastLight - i)) < lights[i]){
                    lastLight = i;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<lights.size();){
            
            if(lights[i] == 0){
                cnt++;
                i += 3;
            }
            else{
                i++;
            }
        }

        // for(int it:lights){
        //     cout << it << " ";
        // }
        //cout << endl;
        return cnt;
    }
};