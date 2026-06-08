class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int l= 0;
        for(int r=1;r<intervals.size();r++){
            if(intervals[l][1]> intervals[r][0])
            {
                if(intervals[l][1]> intervals[r][1]){
                    l=r;
                    count++;
                }
                else if(intervals[l][1]<=intervals[r][1]){
                    count++;
                }

               
            }
            else{
                l=r;
            }
        }
        return count;
    }
};
