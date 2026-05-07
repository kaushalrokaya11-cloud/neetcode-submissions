class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        int left, right,target;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
             if(i>0 && nums[i]==nums[i-1]) continue;

            target=(-nums[i]);
            left=i+1;
            right=nums.size()-1;
        
                while(left<right)
                {
                    if ( nums[left]+nums[right]> target)
                    {
                        right--;
                    }
                    else if( nums[left]+nums[right]< target)
                    {
                        left++;
                    }
                    else
                    {
                        triplets.push_back({nums[i],nums[left],nums[right]});
                        left++;
                        right--;
                    while( nums[left]==nums[left-1]) left++;
                    while( nums[right]==nums[right+1]) right--;

                    }
                   


                    
                }
        }
    return triplets;
    }
};
