class Solution {
public:
vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        findingCombinations(nums,0,target,{});
        return result;
        
    }
    void findingCombinations(vector<int> nums, int i, int target,vector<int> curr){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0|| i>=nums.size()){
            return;
        }
        vector<int> altCurr=curr;

        curr.push_back(nums[i]);
        findingCombinations(nums,i,target-nums[i],curr);
        curr.pop_back();
        findingCombinations(nums,i+1,target,altCurr);
    }
};
