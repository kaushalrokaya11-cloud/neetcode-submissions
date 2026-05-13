class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;

        for(vector<int> pre: prerequisites){
            int a= pre[0];
            int b= pre[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        for(int i=0;i<numCourses;i++){
            if( indegree[i]==0) q.push(i);
        }

        //dfs
        vector<int> result;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            result.push_back(node);

            for( int i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0){q.push(i);}
            }
        }

        return (result.size()==numCourses)? result: vector<int>{};

        
    }
};
