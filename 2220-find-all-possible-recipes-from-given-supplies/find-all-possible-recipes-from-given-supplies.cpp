class Solution {
public:
    void topoSort(unordered_map<string, vector<string>>& adj, string node, vector<string>& ordering, map<string, int>& vis){
        vis[node] = 1;

        for(string it:adj[node]){
            if(vis[it] == 0){
                topoSort(adj, it, ordering, vis);
            }
        }

        ordering.push_back(node);
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> s;
        unordered_set<string> r;
        for(string it:supplies){
            s.insert(it);
        }

         for(string it:recipes){
            r.insert(it);
        }

        unordered_map<string, vector<string>> adj; // dependents list for each recipe {recipe -> dependent recipe}
        unordered_map<string, vector<string>> m; // recipe and ingredients mapping
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(r.find(ingredients[i][j]) != r.end()){
                    adj[ingredients[i][j]].push_back(recipes[i]);
                }
                m[recipes[i]].push_back(ingredients[i][j]);
            }
        }

        vector<string> ordering;
        map<string, int> vis;
        // to take care of connected components
        for(string recipe : recipes){
            if(vis[recipe] == 0){
                topoSort(adj, recipe, ordering, vis);
            }
        }
        

        reverse(ordering.begin(), ordering.end());

        vector<string> ans;
        for(string it : ordering){
            int flag = 1;
            for(string ing : m[it]){
                if(s.find(ing) == s.end()){
                    flag = false;
                    
                }
            }
            if(flag){
                s.insert(it);
                ans.push_back(it);
            }
        }
        return ans;
    }
};