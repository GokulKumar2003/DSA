class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
    //    if(n==1){
    //         return 0;
    //    }
    //    unordered_map<int, vector<vector<int>>> m;
    //    for(auto it : edges){
    //         m[it[0]].push_back({it[1], it[2], it[3]});
    //    }

    //     priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    //     q.push({0, 0});
    //     vector<int> T(n, INT_MAX);

    //     while(q.size()){
    //         int time = q.top().first;
    //         int node = q.top().second;
    //         q.pop();
    //         if(node == n-1){
    //             return time;
    //         }
    //         if(time >= T[node]){
    //             continue;
    //         }
    //         T[node] = time;

    //         for(auto it : m[node]){
    //             if(time <= it[2]){
    //                 time = max(time, it[1]);
    //                 time++;
    //                 if(time < T[it[0]]){
    //                     q.push({time, it[0]});
    //                 }
    //             } 
    //         }            
    //     }

    //    return -1;

    vector<int> dp(n, 2e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
        h.push({0, 0});
        vector<vector<vector<int>>> G(n);
        for (const auto& edge : edges) {
            G[edge[0]].push_back({edge[1], edge[2], edge[3]});
        }
        while (!h.empty()) {
            auto [t, u] = h.top();
            h.pop();
            if (u == n - 1) {
                return t;
            }
            if (t >= dp[u]) {
                continue;
            }
            dp[u] = t;

            for (const auto& edge : G[u]) {
                int v = edge[0], s = edge[1], e = edge[2];
                if (t <= e) {
                    int t2 = max(s, t) + 1;
                    if (t2 < dp[v]) {
                        h.push({t2, v});
                    }
                }
            }
        }
        return -1;
    }
};