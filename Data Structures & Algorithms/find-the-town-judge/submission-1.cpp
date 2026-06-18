class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> hset;
        
        vector<vector<int>> adj(n+1);

        for(auto tr: trust){
            adj[tr[1]].push_back(tr[0]);
            hset.insert(tr[0]);
        }
        for(int i=0;i<n+1;i++){
            if(adj[i].size() == n-1 && !hset.count(i)){
                return i;
            }
        }
        return -1;
        
    }
};