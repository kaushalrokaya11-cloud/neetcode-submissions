class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        for(auto num: nums){
            if(hset.count(num)){
                return true;
            }
            hset.insert(num);
        }
        return false;

    }
};