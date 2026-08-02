class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int nums_with_duplicates= 0;
        unordered_map<char, int> freq;
        int l =0,r = 0;
        int res = 0;

        while(r<s.length()){
            if(freq[s[r]]==1){
                nums_with_duplicates++;
            }
                freq[s[r]]++;

            if(nums_with_duplicates>0){
                freq[s[l]]--;
                if(freq[s[l]]==1){
                    nums_with_duplicates--;
                }
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
        
    }
};
