class Solution {
public:
vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        // sort(nums.begin(),nums.end());
        findingCombinations(nums,0,target,0,curr);
        return result;
    }
    void findingCombinations(vector<int> nums, int i, int target, int total,
     vector<int> curr){

        if(total==target){result.push_back(curr);}
        if(total>target){return;}
        for(int j=i;j<nums.size();j++){
            curr.push_back(nums[j]);
            findingCombinations(nums,j,target, total+nums[j],curr);
            curr.pop_back();
        }

    }

};
