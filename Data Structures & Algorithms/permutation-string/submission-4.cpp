class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> s1_freq(26),window_freq(26);
        for(int i = 0;i<s1.length();i++){
            s1_freq[s1[i]-'a']++;
        }
        int l = 0,r ;
        for(int i = 0;i<s1.length()-1;i++){
            window_freq[s2[i]-'a']++;
        }
        for(int r = s1.length()-1;r<s2.length();r++){
            window_freq[s2[r]-'a']++;
            if(s1_freq == window_freq){return true;}
            window_freq[s2[l]-'a']--;
            l++;
        }
        return false;
    }
};
