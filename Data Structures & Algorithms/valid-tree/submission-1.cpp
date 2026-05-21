class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        queue<pair<int,int>> q;
        unordered_set<int> curr;

        for(vector<int> edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

            q.push({0,-1});
            curr.insert(0);
            return bfs(adj,q,curr,n);

        
    }
    bool bfs(vector<vector<int>> &adj,queue<pair<int,int>> &q, unordered_set<int> &curr, int n){
        int total=1;
        while(!q.empty()){
            auto [node,parent]= q.front();
            q.pop();
            for(auto nd: adj[node]){
                if(nd==parent){
                    continue;
                }
                if(curr.count(nd)){return false;}
                q.push({nd,node});
                curr.insert(nd);
                total++;

            }
        }
        return (total==n);
    }
};
