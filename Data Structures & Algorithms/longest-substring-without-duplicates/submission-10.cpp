class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0,r=0,res=0;
        unordered_set<char> hset; 
        for(int r =0;r<s.length();r++){
            while(hset.count(s[r])){
                hset.erase(s[l]);
                l++;
            }
            hset.insert(s[r]);
            res = max(res,r-l+1);
        }
        return res;
    }
};
