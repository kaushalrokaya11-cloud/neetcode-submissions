class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //figure out the size of queue
        priority_queue<int> pq;
        unordered_map<int,int> freq;
        vector<int> res;
        int l =0;
        for(int i = 0;i<k-1;i++){
            freq[nums[i]] ++;
            pq.push(nums[i]);
        }
        for(int r = k-1;r<nums.size();r++){
            pq.push(nums[r]);
            freq[nums[r]]++;
            while(freq[pq.top()]==0){
                pq.pop();
            }
            int val = pq.top();
            res.push_back(val);
            freq[nums[l]]--;
            l++;   
        }
        return res;
        
    }
};
