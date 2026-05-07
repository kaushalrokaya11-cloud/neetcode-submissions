class Solution {
public:
    int rob(vector<int>& nums) 
    {
        
       if(nums.size()==0){return 0;}
       else if( nums.size()==1){return nums[0];}
       else if(nums.size()==2){return max(nums[0],nums[1]);}
       else if(nums.size()==3){return max(nums[0]+nums[2],nums[1]);}
       
       else
       {
        int prev1=nums[0]+nums[2];
        int prev2=nums[1];
        int prev3=nums[0];

        for(int i=3;i<nums.size();i++)
        {
            int curr= max(nums[i]+prev2,nums[i]+prev3);
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return max(prev1,prev2);
       }
       
        
    }
};
