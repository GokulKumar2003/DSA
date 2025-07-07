class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
       if(n==1){
            return 0;
       }
       vector<vector<int>> m[n];
       for(auto it : edges){
            m[it[0]].push_back({it[1], it[2], it[3]});
       }

        priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        vector<int> T(n, INT_MAX);

        while(q.size()){
            int time = q.top().first;
            int node = q.top().second;
            q.pop();
            if(node == n-1){
                return time;
            }
            if(time >= T[node]){
                continue;
            }
            T[node] = time;

            for(auto it : m[node]){
                int temp = time;
                if(temp <= it[2]){
                    temp = max(time, it[1]);
                    temp++;
                    if(temp < T[it[0]]){
                        q.push({temp, it[0]});
                    }
                } 
            }            
        }

       return -1;

    }
};