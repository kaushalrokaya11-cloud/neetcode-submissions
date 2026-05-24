class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        vector<vector<int>> result;

        for(vector<int> point:points){
            int x= point[0];
            int y= point[1];

            int dist= x*x + y*y;

            maxHeap.push({dist,{x,y}});
            if(maxHeap.size()>k) maxHeap.pop();
        }
        while(!maxHeap.empty()){
            pair<int,pair<int,int>> p= maxHeap.top();
            maxHeap.pop();

            result.push_back({p.second.first, p.second.second});

        }
        return result;
    }
};
