class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int c=0;
        unordered_map<int,int> temp;
        unordered_map<int,vector<int>> map;
        vector<int> arr;
        for(int x: nums)
        {
            temp[x]++;
        }
        for(auto pair: temp){
            map[pair.second].push_back(pair.first);
        }
        for(int i=nums.size();i>=1;i--){
            if(map.find(i)!=map.end()){
                for( int j=0;j<map[i].size();j++){
                    arr.push_back(map[i][j]);
                    c++;
  
                
                if(c==k) return arr;}
            }
        }
        return arr;
    }

    
};
