class TaskManager {
public:
    map<int, int> taskToPriority;
    map<int, int> taskToUser;
    priority_queue<pair<int, int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            taskToPriority[tasks[i][1]] = tasks[i][2];
            taskToUser[tasks[i][1]] = tasks[i][0];
            pq.push({tasks[i][2], tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToPriority[taskId] = priority;
        taskToUser[taskId] = userId;
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        if(taskToPriority[taskId] == newPriority){
            return;
        }
        taskToPriority[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskToPriority.erase(taskId);
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        while(pq.size()){
            int taskId = pq.top().second;
            int priority = pq.top().first;
            
            if(taskToPriority.find(taskId) == taskToPriority.end() || taskToPriority[taskId] != priority){
                pq.pop();
                continue;
            }
            else{
                pq.pop();
                int userId = taskToUser[taskId];
                taskToPriority.erase(taskId);
                taskToUser.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */