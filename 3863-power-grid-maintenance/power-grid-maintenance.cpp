class Solution {
public:
    vector<int> parent;
    vector<int> size;

    void DSU_init(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u != parent_v){
            if(size[parent_u] < size[parent_v]){
                size[parent_v] += size[parent_u];
                parent[parent_u] = parent_v;
            }
            else{
                size[parent_u] += size[parent_v];
                parent[parent_v] = parent_u;
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<int> arr; // to store ans
        unordered_map<int, set<int>> m; // component num -> {nodes in that component};

        DSU_init(c);

        for(auto it:connections){
            Union(it[0], it[1]);
        }

        for(int i=1;i<=c;i++){
            m[findParent(i)].insert(i);
        }

        for(auto it:queries){
            int op = it[0];
            int node = it[1];
            int ans = -1;
            if(op == 1){
                set<int>& s = m[findParent(node)];
                if(s.find(node) != s.end()){
                    ans = node;
                }
                else {
                    if(s.size()){
                        ans = *s.begin();
                    }
                }
                arr.push_back(ans);
            }
            else{
                m[findParent(node)].erase(node);
            }
        }
        return arr;
    }
};