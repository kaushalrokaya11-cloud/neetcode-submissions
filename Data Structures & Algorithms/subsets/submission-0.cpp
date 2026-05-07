class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        findingSubsets(nums,0,{});
        return result;
        
    }
    void findingSubsets(vector<int> nums,int i,vector<int>curr){
        if(i>=nums.size()){result.push_back(curr);return ;}

        vector<int> altVec=curr;
        curr.push_back(nums[i]);
        findingSubsets(nums,i+1,curr);
        findingSubsets(nums,i+1,altVec);
    }
};
