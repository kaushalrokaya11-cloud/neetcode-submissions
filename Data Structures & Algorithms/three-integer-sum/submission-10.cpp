class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;

            int l = i+1;
            int r = n-1;
            int target = -nums[i];

            //handling two sum with duplicates;

            while(l<r){
                 while(l>i+1 && l<r && nums[l]==nums[l-1])l++;
                while(r<n-1 && l<r && nums[r]==nums[r+1])r--;
               
                if(l!=r && nums[l]+nums[r]==target){
                    result.push_back({nums[i],nums[l],nums[r]});
                    l++;
                }
                else if (nums[l]+nums[r]<target){
                    l++;
                }
                else if (nums[l]+nums[r]>target){
                    r--;
                }
               
            }


        }
        return result;
    }
};
