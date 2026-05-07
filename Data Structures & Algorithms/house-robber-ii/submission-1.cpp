class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1){return nums[0];}
        return max(robber(1,nums.size(),nums),robber(0,nums.size()-1,nums));    
    }
    int robber(int start, int end,  vector<int> &nums)
    {
        int prev1=0;
        int prev2=0;
        int prev3=0;

        for(int i=start;i<end;i++){
            int curr= max(nums[i]+prev2,nums[i]+prev3);
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return max(prev1,prev2);
    }
};
