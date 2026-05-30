class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.size()==0)return intervals;
        vector<vector<int>> result;

        int upperB = intervals[0][1];
        int lowerB = intervals[0][0];

        for(auto interval:intervals){

            int curr_lowerB= interval[0];
            int curr_upperB= interval[1];
            if(upperB >= curr_lowerB){
                lowerB= min(curr_lowerB, lowerB);
                upperB= max(curr_upperB, upperB);
            }
            else{
                result.push_back({lowerB,upperB});
                cout<<" Pushed:"<< lowerB<<" "<< upperB;

                upperB= curr_upperB;
                lowerB= curr_lowerB;
            }
            


        }
        result.push_back({lowerB,upperB});
        return result;
        
    }
};
