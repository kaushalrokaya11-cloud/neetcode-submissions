class Solution {
public:
vector<int>curr;
vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        findingCombinations(candidates, target, 0,0);
    return result;
        
    }
    void findingCombinations(vector<int> candidates,int target,int i,int total)
{
    if(total==target){result.push_back(curr);return;}
    if(total>target){return;}
    // if(i>=candidates.size()){return;}
    


    for(int j=i;j<candidates.size();j++){
        if(j>0 && j>i && candidates[j]==candidates[j-1]){continue;}
        curr.push_back(candidates[j]);
        findingCombinations(candidates,target,j+1,total+candidates[j]);
        curr.pop_back();
    }



}
};

