class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            // if window is invalid, shrink it
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l+1 );
        }

        return maxLen;
    }
};