class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int,vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        for(int i=0;i<numCourses;i++){
            graph[i]={};
        }

        for(vector<int> pre: prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        for( int i=0;i< numCourses;i++){

        bool res= dfs(i);
        if(!res)return false;
        }
        return true;
    }
    bool dfs(int node){
        if(visited.count(node)){return false;}

        if(graph[node].empty()){return true;}

        visited.insert(node);
        for(int nd: graph[node]){
            bool res= dfs(nd);
            if (!res) return false;
        }
        visited.erase(node);
        // graph[node].clear();
        return true;

    }
};
