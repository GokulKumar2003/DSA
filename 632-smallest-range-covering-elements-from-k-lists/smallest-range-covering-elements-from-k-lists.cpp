class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        

        vector<pair<int, int>> arr;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                arr.push_back({nums[i][j], i});
            }
        }

        sort(arr.begin(), arr.end());
        map<int, int> m;

        int i=0,j=0;
        vector<int> range(2);
        range[0] = 0;
        range[1] = INT_MAX;
        while(j<arr.size()){
            int num = arr[j].first;
            int listNum = arr[j].second;
            m[listNum]++;

            while(m.size() == n){
                int l = arr[i].first, r = arr[j].first;
                if((r - l) < (range[1] - range[0])){
                    range[0] = l;
                    range[1] = r;
                }

                m[arr[i].second]--;
                if(m[arr[i].second] == 0){
                    m.erase(arr[i].second);
                }
                i++;
            }
            j++;
        }


        return range;
    }
};