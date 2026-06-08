/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n= intervals.size();
        if(n==1|| n==0) return true;
        vector<vector<int>> vintervals;
        for( auto interval: intervals){
            vintervals.push_back({interval.start,interval.end});
        }
        sort(vintervals.begin(),vintervals.end());

        for(int i=1;i<n;i++){
            if(vintervals[i-1][1]>vintervals[i][0]) return false;
        }
        return true;
        
        
    }
};
