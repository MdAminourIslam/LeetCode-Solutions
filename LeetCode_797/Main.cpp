#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int parent, vector<int> cur, vector<vector<int>>& paths, vector<vector<int>>& graph) {
        cur.push_back(parent);
        if (parent + 1 == graph.size()) {
            paths.push_back(cur);
            return;
        }
        
        for (int child : graph[parent]) {
            dfs(child, cur, paths, graph);
        }
    } 

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> cur;
        dfs(0, cur, paths, graph);
        return paths;
    }
};