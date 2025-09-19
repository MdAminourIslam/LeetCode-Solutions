#include<bits/stdc++.h>
using namespace std;


class TaskManager {
public:
    map<int, int> userIdMap, priorityMap;
    set<pair<int, int>> st; // { -priority, -taskId }

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            userIdMap[taskId] = userId;
            priorityMap[taskId] = priority;
            st.insert({-priority, -taskId}); 
        }
    }

    void add(int userId, int taskId, int priority) {
        userIdMap[taskId] = userId;
        priorityMap[taskId] = priority;
        st.insert({-priority, -taskId});
    }

    void edit(int taskId, int newPriority) {
        int oldPriority = priorityMap[taskId];
        st.erase({-oldPriority, -taskId});
        st.insert({-newPriority, -taskId});
        priorityMap[taskId] = newPriority;
    }

    void rmv(int taskId) {
        int oldPriority = priorityMap[taskId];
        st.erase({-oldPriority, -taskId});
        userIdMap.erase(taskId);
        priorityMap.erase(taskId);
    }

    int execTop() {
        if (!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());
            int taskId = -top.second;          
            int userId = userIdMap[taskId];    
            userIdMap.erase(taskId);
            priorityMap.erase(taskId);
            return userId;                     
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