class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int max_count=0;
        unordered_set<int>container(nums.begin(),nums.end());
        auto it =container.begin();

        while(it!=container.end()){
            int num = *it;
            if(container.count(num-1)){
                it++;
                continue;
            }
            int temp_count=0;
            while(container.count(num)){
                temp_count ++;
                num++;
            }

            max_count = max(temp_count, max_count);
            it++;
        }
        return max_count;
        
    }
};
