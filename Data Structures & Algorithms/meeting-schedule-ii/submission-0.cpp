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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        for(auto interval:intervals){
            mp[interval.start]++;
            mp[interval.end]--;
        }
        int res=0;
        int curr=0;
        for(auto [point, value]:mp){
            curr = curr+ value;
            res= max(res, curr);
        }
        return res;
    }
};
