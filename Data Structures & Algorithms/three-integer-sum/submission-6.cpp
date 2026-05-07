class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int i,j,k,c=0,target;
        sort(nums.begin(),nums.end());

        for(k=0;k<nums.size();k++)
        {
            if(k>0 && nums[k]==nums[k-1]){continue;}
            target=-nums[k];
            i=k+1;
            j=nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]<target){
                    i++;
                }
                 else if(nums[i]+nums[j]>target){
                    j--;
                }
                else if(nums[i]+nums[j]==target){
                    result.push_back({nums[i],nums[j],nums[k]});
                    i++;
                    

                     while(i<j&& nums[i]==nums[i-1]){
                    i++;
                }
                    
                }


               
            }
        }
        
        return result;
    }
};