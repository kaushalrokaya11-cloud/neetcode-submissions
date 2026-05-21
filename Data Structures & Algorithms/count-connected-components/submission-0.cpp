class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        int count=0;

        for(vector<int>  edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(visited.count(i)) continue;
        
            count++;
            q.push({i,-1});
            visited.insert(i);
            bfs(adj,q,visited);
            
        }
        return count;

    }
    void bfs( vector<vector<int>> &adj, queue<pair<int,int>> &q, unordered_set<int> &visited){
        while(!q.empty()){
            auto [node,parent]= q.front();
            q.pop();

            for(auto nd:adj[node]){
                if(nd==parent)continue;
                if(visited.count(nd)) continue;

                q.push({nd,node});
                visited.insert(nd);
            }

            
        }
    }
};
