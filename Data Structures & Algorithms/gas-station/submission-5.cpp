class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
       
        

        int l=INT_MAX;
        int total=0;
        int windowSum=0;
        int curr=0;

        for(int i=0;i<n;i++){

            curr= gas[i]-cost[i];
            total= total+ curr;

            windowSum= windowSum+ curr;
            if(windowSum<0) {windowSum=0;l=INT_MAX;}
            else {l=min (i,l); }
        }
        return (total>=0)? l:-1;
    }
};
