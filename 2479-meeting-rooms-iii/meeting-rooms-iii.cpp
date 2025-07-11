class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        map<int, int> m;
        int maxUsedRoom = -1, maxCnt = 0;
        for(int i=0;i<n;i++){
            freeRooms.push(i);
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, int>>> endTime;
        sort(meetings.begin(), meetings.end());
        for(int i=0;i<meetings.size();i++){

            while(endTime.size() && endTime.top().first <= meetings[i][0]){
                long long room = endTime.top().second;
                long long e = endTime.top().first;
                freeRooms.push(room);
                endTime.pop();
            }

            int room;
            if(freeRooms.size()){
                room = freeRooms.top();
                freeRooms.pop();
                m[room]++;
                endTime.push({meetings[i][1], room});
            }
            else{
                room = endTime.top().second;
                long long e = endTime.top().first;
                endTime.pop();
                m[room]++;
                if(meetings[i][0] > e){
                    endTime.push({meetings[i][0] + (meetings[i][1] - meetings[i][0]), room});
                }
                else{
                    endTime.push({e + (meetings[i][1] - meetings[i][0]), room}); 
                }
            }
            if(m[room] > maxCnt){
                maxUsedRoom = room;
                maxCnt = m[room];
            }
            else if(m[room] == maxCnt){
                maxUsedRoom = min(maxUsedRoom, room);
            }
        }


        return maxUsedRoom;
    }
};