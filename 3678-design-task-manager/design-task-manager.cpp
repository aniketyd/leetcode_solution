class TaskManager {
public:
   set<pair<pair<int,int>,int>>st;
unordered_map<int,int>mp,mp2;
    TaskManager(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++){
            st.insert({{tasks[i][2],tasks[i][1]},tasks[i][0]});
        mp[tasks[i][1]]=tasks[i][2];
         mp2[tasks[i][1]]=tasks[i][0];}
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({{priority,taskId},userId});
        mp[taskId]=priority;
        mp2[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
       auto it= st.find({{mp[taskId],taskId},mp2[taskId]});
        st.erase(it);
        st.insert({{newPriority,taskId},mp2[taskId]});
        mp[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
         auto it= st.find({{mp[taskId],taskId},mp2[taskId]});
        st.erase(it);
    }
    
    int execTop() {
        if(st.size()==0)return -1;
        auto it=st.end();
        --it;
        auto f=(*it);
        st.erase(it);
        return f.second;
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