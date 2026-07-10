class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hmap;
        unordered_map<int, vector<int>> freq;
        vector<int> result;
        for(auto num:nums){
            hmap[num]++;
        }
        for(auto &pr:hmap){
            freq[pr.second].push_back(pr.first);
        }
        int count =0;
        for(int i= nums.size();i>=1;i--){
            if(freq.count(i)){
                for(auto n: freq[i]){
                count++;
                result.push_back(n);

                if(count == k){
                cout<<"count ==k";
                return result;}
                }
            }
           
        }
        cout<<"exited for loop";
        return result;

    }
};
