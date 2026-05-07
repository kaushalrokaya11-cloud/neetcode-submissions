class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int prev1=0;
        int prev2=0;
        int prev3=0;

        for(int i=0;i<nums.size();i++)
        {
            int curr= max(nums[i]+prev2,nums[i]+prev3);
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return max(prev1,prev2);
       
       
        
    }
};
