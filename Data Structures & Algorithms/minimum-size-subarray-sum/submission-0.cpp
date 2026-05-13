class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        if(target==0){return 0;}
        int l=0;
        int r=0;
        int sum=nums[0];
        int length=INT_MAX;
      
        while(r<nums.size()){
            
            if(sum>= target)
            {
                length=min(length, r-l+1);
                sum=sum-nums[l];
                l++;
                continue;

            }
            else{
                r=r+1;
                sum=sum+nums[r];
                
            }
            

        }
        return (length==INT_MAX)? 0: length;

    }
};