class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        if(target==0){return 0;}
        int l=0;
        // int r=0;
        int sum=0;
        int length=INT_MAX;
      
      for(int r=0;r<nums.size();r++){
        sum = sum+ nums[r];
        if(sum>= target){
            
            while(sum>=target){
                length = min( length, r-l+1);
                sum-= nums[l];
                l++;
            }
        }
      }
      return (length== INT_MAX)? 0: length;

    }
};