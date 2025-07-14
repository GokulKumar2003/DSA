class Solution {
public:
    vector<int> parent1, parent2;
    vector<int> size1, size2;
    void init_DSU(int n){
        parent1.resize(n+1);
        parent2.resize(n+1);
        size1.resize(n+1, 1);
        size2.resize(n+1, 1);

        for(int i=0;i<=n;i++){
            parent1[i] = i;
            parent2[i] = i;
        }
    }

    void unite1(int u, int v){
        int pu = findParent1(u);
        int pv = findParent1(v);
        if(pu == pv){
            return;
        }
        if(size1[pu] >= size1[pv]){
            parent1[pv] = parent1[pu];
            size1[pu] += size1[pv]; 
        }
        else{
            parent1[pu] = parent1[pv];
            size1[pv] += size1[pu];
        }
    }

    void unite2(int u, int v){
        int pu = findParent2(u);
        int pv = findParent2(v);
        if(pu == pv){
            return;
        }
        if(size2[pu] >= size2[pv]){
            parent2[pv] = parent2[pu];
            size2[pu] += size2[pv]; 
        }
        else{
            parent2[pu] = parent2[pv];
            size2[pv] += size2[pu];
        }
    }

    int findParent1(int u){
        if(u == parent1[u]){
            return u;
        }

        return parent1[u] = findParent1(parent1[u]);
    }

    int findParent2(int u){
        if(u == parent2[u]){
            return u;
        }

        return parent2[u] = findParent2(parent2[u]);
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end(), greater<vector<int>>());
        init_DSU(n);
        int cnt = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][2];
            if(edges[i][0] == 3){
                if(findParent1(u) != findParent1(v) || findParent2(u) != findParent2(v)){
                    unite1(u, v);
                    unite2(u, v);
                }
                else{
                    cnt++;
                }
            }
            else if(edges[i][0] == 2){
                if(findParent2(u) != findParent2(v)){
                    unite2(u, v);
                }
                else{
                    cnt++;
                }
            }
            else{
                if(findParent1(u) != findParent1(v)){
                    unite1(u, v);
                }
                else{
                    cnt++;
                }
            }
        }

        set<int> s1, s2;
        for(int i=1;i<=n;i++){
            findParent1(i);
            if(s1.find(parent1[i]) == s1.end()){
                s1.insert(parent1[i]);
            }
            cout << parent2[i] << " ";
        }
        cout << endl;
        if(s1.size() != 1){
            return -1;
        }
        for(int i=1;i<=n;i++){
            findParent2(i);
            if(s2.find(parent2[i]) == s2.end()){
                s2.insert(parent2[i]);
            }
            cout << parent2[i] << " ";
        }
        cout << endl;
        if(s2.size() != 1){
            return -1;
        }
        return cnt;
    }
};