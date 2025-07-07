class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        int n = friends.size();

        queue<int> q;
        q.push(id);
        vector<int> vis(n);
        vis[id] = 1;
        int l = 0;

        while(q.size()){
            int s = q.size();
            if(l == level){
                map<string, int> m;

                for(int i=0;i<s;i++){
                    int node = q.front();
                    q.pop();
                    cout << node << " ";
                    for(string str : watchedVideos[node]){
                        m[str]++;
                    }
                }
                vector<pair<int, string>> arr;
                    for(auto it:m){
                        arr.push_back({it.second, it.first});
                    }
                    sort(arr.begin(), arr.end());
                    vector<string> ans;
                    for(auto it:arr){
                        ans.push_back(it.second);
                    }
                    return ans;
            }
            else{
                for(int i=0;i<s;i++){
                    int node = q.front();
                    q.pop();
                    for(int it : friends[node]){
                        if(vis[it] == 0){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
            l++;
        }

        return {};
    }
};