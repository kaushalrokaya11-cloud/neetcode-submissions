class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        if(intervals.size()==0)return intervals;
        result.push_back(intervals[0]);

        for(int i=1 ;i<intervals.size();i++){
            auto &last = result.back();

            if( last[1]>= intervals[i][0]){
                last[0]= min(intervals[i][0],last[0]);
                last[1]= max(intervals[i][1],last[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
        
    }
};
