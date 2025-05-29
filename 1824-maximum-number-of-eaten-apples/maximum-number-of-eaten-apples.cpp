class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        int day = 0, cnt = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0;i<days.size();i++){

            pq.push({day + days[i], apples[i]});
            
            while(pq.size() && day >= pq.top().first){
                pq.pop();
            }

            if(pq.size()){
                int rottingDay = pq.top().first;
                int apples = pq.top().second;
                pq.pop();
                cnt++;
                if(apples - 1){
                    pq.push({rottingDay, apples - 1});
                }
            }
            day++;
        }

        while(pq.size()){
            
            while(pq.size()  && day >= pq.top().first){
                pq.pop();
            }
            if(pq.size()){
                int rottingDay = pq.top().first;
                int apples = pq.top().second;
                pq.pop();
                if(apples - 1){
                    pq.push({rottingDay, apples - 1});
                } 
                cnt++;
            }
            day++;
        }

        return cnt;
    }
};