class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;

        for(vector<int> pre: prerequisites){
            int a= pre[0];
            int b= pre[1];

            adj[b].push_back(a);
            indegree[a]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        //bfs
        int count=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            count++;

            for(int dest: adj[node]){
                indegree[dest]--;
                if(indegree[dest]==0) q.push(dest);
            }
        }
        return (count==numCourses);

    }
};
