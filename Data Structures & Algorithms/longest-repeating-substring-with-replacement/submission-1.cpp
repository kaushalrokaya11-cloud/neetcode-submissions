class Solution {
public:
    int characterReplacement(string s, int k) {
       int l=0,r;
       unordered_map<char,int> freq;
       int greatest=0, maxfreq=0;
       for(int r=0;r<s.length();r++){
        freq[s[r]]++;
        maxfreq=max(maxfreq,freq[s[r]]);

        if(maxfreq+k>=r-l+1){//if the window is valid
        greatest=max(greatest,r-l+1);

        }
        else{
            freq[s[l]]--;
            l=l+1;
        }

       }

        return greatest;
    }
};