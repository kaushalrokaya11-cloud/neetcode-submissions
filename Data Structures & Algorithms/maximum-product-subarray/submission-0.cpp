class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int currMax= nums[0];
        int currMin= nums[0];
        int res= nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] <0)
            
            swap(currMin,currMax);
            currMin= min(nums[i], currMin*nums[i]);
            currMax= max(nums[i], currMax*nums[i]);
            

            res= max(res,currMax);
        }
        return res;
    }
};
