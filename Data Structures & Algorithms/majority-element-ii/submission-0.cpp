class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> result;
        int b= nums.size()/3+1;

        for(int num:nums){
            freq[num]++;
            if(freq[num]==b){result.push_back(num);}
        }
        return result;
    }
};