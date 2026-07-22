class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            threeSum(nums,target,result,i);
        }
        return result;
        
    }
    void threeSum(vector<int> &nums, int target, vector<vector<int>>&result,int k1){
        for(int i =k1+1;i<nums.size();i++){
            
            if(i>k1+1 && nums[i]==nums[i-1]){continue;}
            twoSum(nums,target,result,k1,i);
            
        }
    }
    void twoSum(vector<int> &nums, int target, vector<vector<int>>&result,int k1,int k2){
        int l = k2+1; int r  = nums.size()-1;

        while(l<r){
            long long sum = (long long)(nums[l])+nums[r]+nums[k1]+nums[k2];
            if(sum==target){
                result.push_back({nums[l],nums[r],nums[k1],nums[k2]});
                l++;
                
            }
            else if(sum<target){
                l++;
            }
            else{
                r--;
            }
            while(l<r && l>k2+1 && nums[l]==nums[l-1]) l++;
            while(l<r && r<nums.size()-1 && nums[r]==nums[r+1]) r--;

        }
    }
};