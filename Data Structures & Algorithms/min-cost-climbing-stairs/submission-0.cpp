class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        if(cost.size()<=1){return 0;}
        int prev1=0;
        int prev2=0;
        for(int i=2;i<=cost.size();i++)
        {
            int minCost= min(cost[i-1]+prev1,cost[i-2]+prev2);
            prev2=prev1;
            prev1=minCost;
        }
        return prev1;
        
    }
};
