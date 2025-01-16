class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        map<string, int> maxViewed; // user -> max viewed video index
        map<string, long> totalViews; // user -> total views
        map<int, set<string>> viewsToCreators; // views -> users
        long maxViews = 0;
        for(int i=0;i<creators.size();i++){
            totalViews[creators[i]] += views[i];
            maxViews = max(maxViews, totalViews[creators[i]]);
            viewsToCreators[totalViews[creators[i]]].insert(creators[i]);
            if(maxViewed.find(creators[i]) == maxViewed.end()){
                maxViewed[creators[i]] = i;
            }
            else{
                if(views[maxViewed[creators[i]]] < views[i]){
                    maxViewed[creators[i]] = i;
                }
                else if(views[maxViewed[creators[i]]] == views[i]){
                    if(ids[i] < ids[maxViewed[creators[i]]]){
                        maxViewed[creators[i]] = i;
                    }
                }
            }
        }

        set<string> popularCreators = viewsToCreators[maxViews];
        vector<vector<string>> ans;
        for(string it:popularCreators){
            ans.push_back({it, ids[maxViewed[it]]});
        }
        return ans;

    }
};