class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        double totalCost = std::numeric_limits<double>::max();

        double totQual = 0;
        vector<pair<double, int>> wageToQual;

        for(int i=0;i<quality.size();i++){
            wageToQual.push_back({(double)(wage[i])/quality[i], quality[i]});
        }

        sort(wageToQual.begin(), wageToQual.end());

        priority_queue<int> pq;
        for(int i=0;i<wageToQual.size();i++){
            pq.push(wageToQual[i].second);
            totQual += wageToQual[i].second;

            if(pq.size() > k){
                totQual -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                totalCost = min(totalCost, totQual*wageToQual[i].first);
            }
        }

        return totalCost;
    }
};